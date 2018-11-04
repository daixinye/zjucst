#!/bin/bash

mapper=$1
file=$2

g++ -std=c++11 -o mapper $1
cat $2 | ./mapper | sort

