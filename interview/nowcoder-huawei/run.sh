#!/bin/bash
lang=$1
filename=$2

sourcePath="./source/$filename.$lang"
inputPath="./input"


case $lang in
    js)
        echo "当前 Node 版本:"
        node -v
        echo "cat $inputPath > node $sourcePath"
        echo ""

        cat $inputPath | node $sourcePath
        ;;
    cpp)
        echo "cat $inputPath > node $sourcePath"
        echo ""

        cat $inputPath | node $sourcePath
        ;;
    py)
        ;;
    *)
        echo invalid language
        exit 1
        ;;
    esac

