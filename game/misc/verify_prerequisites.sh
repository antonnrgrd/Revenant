#!/bin/bash

GIT=$(which git)
GCC=$(which gcc)
echo "Verifying software prerequisites"
if [ -z $GIT ]; then
        echo "Could not find git. Please ensure it is installed"
fi

if [ -z $GCC ]; then
        echo "Could not find gcc. Please ensure it is installed"
fi
