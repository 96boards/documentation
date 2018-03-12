---
title: Contributing to Linaro releases for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/downloads/contribute.md.html
redirect_from:
- /db410c-getting-started/Downloads/Contribute.md/
-  /documentation/ConsumerEdition/DragonBoard-410c/Downloads/Contribute.md.html
---
# Contributing to Linaro releases for Dragonboard 410c

This page provides instructions for developers willing to contribute to the Linaro releases for Dragonboard 410c. This is applicable to the following components:
* Linaro maintained kernel (a.k.a LT kernel)
* Linaro Debian builds
* Linaro OpenEmbedded builds

# How to contribute

The following mailing list has been created to contributions:

https://lists.96boards.org/mailman/listinfo/dragonboard

This is a public mailing open to any developer.

# General recommendations

* This mailing list is not a substitute for proper upstreaming. We are willing to accept patches against our release (e.g. generally that means against a stable/LTS branch), if the submitters are also willing to upstream their changes. We will not be maintaining orphaned patches forever.
* It is recommended to upstream your changes first into mainline kernel, and then send a backport for inclusion into our release branch. When sending backport patches, please use `git cherry-pick -x <commit>` to make sure that we keep a record about the upstream commit in the commit log.
* Patches should be sent to the mailing list, as inline patches.
* When we do kernel upgrade we might not carry external patches, and they will have to be sent and tested again, if they have not been upstreamed in between.
* When patches add support for new hardware (such as other boards based on the same chipset), Linaro will not test, nor support these additional boards. It will be the submitter responsibility to maintain and test these patches over time, and also answer any support request (on the mailing list, on the forum or on IRC).
* The mailing list is for patches and code. Regular support will continue to be on the 96boards forum
* We expect all discussions to be held on the public mailing list and discourage private discussions over emails as much as possible.
* Of course any patches will be reviewed by the maintainers of the involved sub projects, and these developers are responsible to accept or refuse any contribution.
