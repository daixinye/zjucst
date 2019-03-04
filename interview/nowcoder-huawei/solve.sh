#!/bin/bash
echo "choose language(js/cpp/py):"
read lang
echo "input file name: "
read filename

sourcePath="./source/$filename.$lang"
inputPath="./input"

case $lang in
    js)
        ;;
    cpp)
        ;;
    py)
        ;;
    *)
        echo invalid language
        exit 1
        ;;
    esac

cat ./template/t.$lang > "$sourcePath"

echo "" > $inputPath 

code $sourcePath
code $inputPath