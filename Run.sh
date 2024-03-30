#!/bin/bash

if [-d build]; then
    ./build/SpaceShips

else
    ./Build.sh
    cd build
    ./SpaceShips
fi

