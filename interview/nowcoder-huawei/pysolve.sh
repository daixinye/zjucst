#!/bin/bash

name=$1
path=./source/$name.py
echo $path

echo "import sys " > $path
echo "for line in sys.stdin:" >> $path
echo "   " >> $path

echo "" > ./input

code $path
code ./input
