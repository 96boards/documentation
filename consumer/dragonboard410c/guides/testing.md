---
title: Testing Guide for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/guides/Testing.md.html
redirect_from:
- /db410c-getting-started/Guides/Testing.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/Testing.md.html
---
# Introduction

This page is intended to show how to utilize the Linaro test suite on Dragonboard 410c, and more especially how to use the Linaro test suite to run test plans _locally_ on boards available on the developer's desk.

More information about LAVA and LAVA test definitions can be found on https://validation.linaro.org/.

# Linaro test suite

It is an open source test suite maintained by Linaro Q&A team that uses LAVA standardized test definition format:
 1. Test description (metadata)
 1. Test content (steps to run tests)
 1. Test output parsing (pass/fail/measurement/unit)

About ~100 tests cases already exist and are maintained by Linaro. It is possible to run these tests remotely on a LAVA instance, and it is also possible to run the tests _locally_ on boards available on a developer's desk, using a tool called `test-runner`.

# LAVA tests

 * LAVA test definition format defined here: https://validation.linaro.org/static/docs/v2/writing-tests.html
 * Specific guidelines when using `test-runner`: https://git.linaro.org/qa/test-definitions.git/tree/automated/doc/test-writing-guidelines.rst
 * Centralized repo of Linaro test cases: https://git.linaro.org/qa/test-definitions.git/
 * Writing test case: https://git.linaro.org/qa/test-definitions.git/tree/automated/linux
 * Test plan sample: https://git.linaro.org/landing-teams/working/qualcomm/lt-ci.git/tree/plans/smoke.yaml

# Using test-runner to run tests locally

The tests can be run directly on the board, assuming you have installed basic tools such as git, gcc, ... `test-runner` is written in Python and requires `pexpect` and `yaml` modules to be installed as well. To run tests directly on the board, get a prompt and run:

    git clone http://git.linaro.org/qa/test-definitions.git
    git clone https://git.linaro.org/landing-teams/working/qualcomm/lt-ci.git/
    cd test-definitions
    source automated/bin/setenv.sh
    test-runner -p ../lt-ci/plans/smoke.yaml

By default the test output are stored in `$HOME/output/`, and the output folder can be configured with `-o` argument.

# Using test-runner to run tests from host PC

It is also possible to run tests from a host PC if the board is available on the network. In that case `test-runner` will connect to the board over SSH, and you need to setup the board so that the host PC can connect to the board over SSH without any prompt (password less connection). To run from the host, run the following commands from the host command prompt:  

    git clone http://git.linaro.org/qa/test-definitions.git
    git clone https://git.linaro.org/landing-teams/working/qualcomm/lt-ci.git/
    cd test-definitions
    source automated/bin/setenv.sh
    test-runner -g root@ip -p ../lt-ci/plans/smoke.yaml

Where `root@ip` is the credential to connect to the board over SSH.

By default the test output are stored in `$HOME/output/root@ip`, and the output folder can be configured with `-o` argument.

# Running individual tests

Instead of running a test plan with `-p` argument, it is possible to run a single test only using `-d` argument.

# Test output

At the end of the test run, the following artefact are available in the output folder:
 * `result.csv` and `result.json` which contain summary of test results (including test name, test case ID, test results such as pass, fail, skip, test measurement, if any, with the associated measurement unit, and the test argument used
 * For each test executed, there is a folder which contains the console output of the test run, `stdout.log` as well as all test scripts/data
