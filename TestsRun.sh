#!/bin/bash

if [ -e /build/TESTURNNER ] ; then
    ./build/TESTRUNNER

else
    ./Build.sh
    cd build
    ./TESTRUNNER
fi

