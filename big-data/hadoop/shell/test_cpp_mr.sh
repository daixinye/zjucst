#!/bin/bash

mapper=$1
reducer=$2
data=$3

g++ -o mapper $1
g++ -o reducer $2

echo $data | ./mapper | sort | ./reducer