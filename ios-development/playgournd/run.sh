#!/bin/bash

name=$1

ls $name.m &> /dev/null

if [[ $? == 0 ]]; then
    gcc -framework Foundation $name.m -o test
    ./test
else
    echo $name.m not found
fi