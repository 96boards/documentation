#!/bin/bash
#
# Calls the link checker container to run the tool against the current directory.
#
# The script is slightly more complicated that it could otherwise be because the
# parameters to the tool can reference files and these will typically be in the
# directory above the current directory, so we have to volume-map the parent
# directory and tell the tool to check *this* directory.

DIRNAME="$(basename "$(pwd)")"
PARENT="$(dirname "$(readlink -f .)")"

if [ -z "$LINKCHECK" ]; then
  LINKCHECK=latest
fi

# Make sure that the script is not in the current directory. The output from Jekyll
# should be in a sub-directory of the git repository.
SCRIPTDIR="$(dirname "$(readlink -f "$0")")"
if [ "$SCRIPTDIR" == "$(pwd)" ]; then
  echo "Script is being run incorrectly. Go into the built site directory and"
  echo "then run:"
  echo
  echo "../check-links.sh"
  exit 1
fi

docker run \
  --cap-drop ALL \
  --rm \
  -t \
  -v /etc/passwd:/etc/passwd:ro \
  -v /etc/group:/etc/group:ro \
  -u "$(id -u)":"$(id -g)" \
  -v "$PARENT":/srv \
  linaroits/linkcheck:"$LINKCHECK" \
  -d "$DIRNAME" "$@"
