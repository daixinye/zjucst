#!/bin/bash

name=$1
echo $name
echo "#include <iostream>" > ./source/$name.cpp
echo "using namespace std;" >> ./source/$name.cpp 
echo "" >> ./source/$name.cpp 
echo "int main() {" >> ./source/$name.cpp 
echo "  return 0;" >> ./source/$name.cpp
echo "}" >> ./source/$name.cpp

code ./source/$name.cpp