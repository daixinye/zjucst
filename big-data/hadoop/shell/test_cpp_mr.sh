#!/bin/bash

file=$1
cat $1 | ./mapper | sort | ./reducer