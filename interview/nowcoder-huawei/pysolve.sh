#!/bin/bash

name=$1
path=./source/$name.py
echo $path

cat ./py.template > $path

echo "" > ./input

code $path
code ./input
