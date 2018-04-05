---
title: Contribution Policy
permalink: /documentation/CONTRIBUTE.md.html
redirect_from: /documentation/Extras/ContributionPolicy.md.html
---

# Contributing to 96Boards Documentation

Thanks for stopping by to contribute the mezzanine-community repository! The following is a set of guidelines for contributing.

**NOTE: This documentation is solely for the 96Boards Documentation Repository, for filing bugs and issues about the boards themselves please refer to: [Report A Bug](Extras/Report_a_bug.md)**

## Table Of Contents

- [Bugs and Suggestions](#bugs-and-suggestions)
- [Contribution](#contribution)
  - [General Contribution and Bug-Fixes](#general-contribution-and-bug-fixes)
  - [Adding a New Boards](#adding-a-new-boards)
  - [Guidelines for submitting a Pull Request](#guidelines-for-submitting-a-pull-request)

## Bugs and Suggestions

Before attempting to fix the issue/bug on your own, it is recommended to open an issue using the [built-in issues page](https://github.com/96boards/documentation/issues) provided in this GitHub repository. One of our maintainers will get around to your issue as soon as possible. After review, the maintainer may fix the issue on his/her own, or request the subject step in to fix the observed issue. If inclined, at this point you should fork the repository, make said edits, and submit a [Pull Request](https://help.github.com/articles/about-pull-requests/).

- More information on [GitHub issues](https://guides.github.com/features/issues/).
- More information on submitting a [Pull Request](https://help.github.com/articles/about-pull-requests/)

Please make sure you comply with the following criteria when creating/submitting your issue:

- **Use a clear and descriptive title** for the issue to identify the problem/suggestion.
- **Describe the exact steps to reproduce the problem** in as many details as possible in the case of a problem or suggestion
- **Mention location** where was this issue is found / what will your suggestion affect.

***

## Contribution

### General Contribution and Bug-Fixes:

 Community contributions are always Welcome! This section is intended to help anyone interested in contributing to this repository. Before contributing, first get the approval from repository maintainers and community by raising a [GitHub issue](https://github.com/96boards/documentation/issues) using the guidelines mentioned above.

After getting approval, you will need to do the following(these instructions assume you are a [GitHub user](https://github.com/join):
- ###### Step 1: [Fork this repository](https://help.github.com/articles/fork-a-repo/)

- ###### Step 2: Make changes, commit and push to your fork

- ###### Step 3: Submit Pull Request

***

### Adding a New Boards:

If you have recently launched a new 96Boards and have to add it to the documentation repository.
- Arrange your documentation material following the [Template](templates/board-template)
- Copy you board folder under the right Edition category folder
  - [Consumer Edition(CE)](consumer)
  - [Enterprise Edition(EE)](enterprise)
  - [Internet of Things Edition(IE)](iot)
- Send in a Pull Request

Things To Remember: Before sending the Pull request make sure:
- Make sure all the .md files have the headers in place, these headers make sure that the web page is properly generated and place at the correct location.
  - All the files in the template have the headers commented out like so:
    ```
    <!---
    ---
    title: Using the boardname
    permalink: /documentation/consumer/boardname/
    ---
    -->
    ```
  - Make sure to un-comment them like so:
    ```
    ---
    title: Using the boardname
    permalink: /documentation/consumer/boardname/
    ---
    ```
  - And modify them according to your board
- Make sure to place all the images in the ```assets/images``` folder with the correct resolution as mentioned in the template.

***

### Guidelines for submitting a Pull Request:
- **1: Make sure you sign-off your commit and pull request:** You can add it using the git command ```$ git commit -s .``` or manually add it to your commit and pull request ```Signed-off-by: NAME <committer-email>```
- **2: Start with a one-line summary (50 characters maximum), followed by a blank line. This format is used by git and Gerrit for various displays.**
- **3: Starting on the third line, enter a longer description:** This description should focus on what issue the change solves, and how it solves it. The second part is somewhat optional when implementing new features, though desirable.
- **4: Here is an example commit message:**
  ```
  short description on first line

  more detailed description of your patch,
  which is likely to take up multiple lines.
  ```
- **5: If you are new to git:** There are some excellent guide on the internet.
  - [Getting Started - Git Basics](https://git-scm.com/book/en/v2/Getting-Started-Git-Basics)
  - [https://guides.github.com/activities/hello-world/](https://guides.github.com/activities/hello-world/)


***

**For any additional questions/help, please visit us in IRC Channel: #96boards**
