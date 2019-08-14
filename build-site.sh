#!/bin/bash

check_multi_repo() {
  # A multi-repo site is defined by the presence of manifest.json.
  #
  # If that file exists, we look for the tags in the file, which
  # specifies the env var names that must be used to tell this
  # script where a local copy of that repo can be found.
  #
  # We then build up a list of mounts for Docker so that it can
  # access those repo copies.
  #
  # Use -g to make this a global variable (i.e. it lasts after
  # the function finishes).
  declare -a -g DOCKER_MOUNTS
  DOCKER_MOUNTS=()
  if [ ! -f "manifest.json" ]; then
    echo "No multi-repo configuration to manage."
    return
  fi
  #
  # Get the tags from the file.
  declare -a tags
  tags=($(grep \"tag\" manifest.json | cut -d':' -f2))
  tag_count="${#tags[@]}"
  if [ "$tag_count" == 0 ]; then
    echo "Cannot find repo tags in manifest file."
    exit 1
  fi
  #
  # Do any of them exist as variables that point to directories?
  for ((i=0; i < tag_count; i++))
  do
    # Need to strip extraneous chars off the tag string
    tag="${tags[$i]}"
    # Strip the leading " and the trailing ",
    tag="${tag:1:-2}"
    # Does that tag name exist as a variable and have a value?
    tag_val="${!tag}"
    if [ "$tag_val" != "" ]; then
      # Does the value point to a directory?
      if [ -d "$tag_val" ]; then
        # Construct a Docker mount command
        DOCKER_MOUNTS+=(-v $tag_val:/srv/$tag)
      fi
    fi
  done
}

check_environment_variables() {
  if [ -z "$JEKYLLSITEBUILD" ]; then
    export JEKYLLSITEBUILD=latest
  fi
  if [ -z "$JEKYLL_ENV" ]; then
    export JEKYLL_ENV=staging
  fi
  if [ "$JEKYLL_ACTION" = "serve" ]; then
    PORTS="-p 4000:4000"
  else
    PORTS=""
  fi
}

check_interactive_running() {
  # Are we running interactively or via Bamboo?
  if [ -t 1 ]; then
    INTER="-i"
  else
    INTER=""
  fi
}

check_multi_repo
check_environment_variables
check_interactive_running

docker run \
  --cap-drop ALL \
  --rm \
  -t \
  $INTER \
  $PORTS \
  -e JEKYLL_ACTION \
  -e JEKYLL_ENV \
  -v /etc/passwd:/etc/passwd:ro \
  -v /etc/group:/etc/group:ro \
  "${DOCKER_MOUNTS[@]}" \
  -u "$(id -u)":"$(id -g)" \
  -v "$(pwd)":/srv/source \
  linaroits/jekyllsitebuild:"$JEKYLLSITEBUILD" \
  "$@"
