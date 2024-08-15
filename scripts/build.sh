#!/usr/bin/env bash

reset
cd ../build

if [ ! -d "obj" ]; then
    mkdir "obj"
fi

cd obj

pwd
cmake --build .. --target install