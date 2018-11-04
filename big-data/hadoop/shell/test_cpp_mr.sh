#!/bin/bash

mapper=$1
reducer=$2
data=$3

g++ -std=c++11 -o mapper $1
g++ -std=c++11 -o reducer $2

echo $data | ./mapper | sort | ./reducer