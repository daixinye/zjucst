#!/bin/bash

name=$1

ls $name.m &> /dev/null

if [[ $? == 0 ]]; then
    gcc -framework Foundation $name.m -o test
    if [[ $? == 0 ]];then
        ./test $2 $3 $4 $5
    fi
else
    echo $name.m not found
fi