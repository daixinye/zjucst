#!/bin/bash
HADOOP_HOME=/usr/local/hadoop
INPUT_PATH=$1
OUTPUT_PATH=$2
echo "Clearing output path: $OUTPUT_PATH"
$HADOOP_HOME/bin/hadoop fs -rmr $OUTPUT_PATH
 
${HADOOP_HOME}/bin/hadoop jar\
   ${HADOOP_HOME}/share/hadoop/tools/lib/hadoop-streaming-2.9.1.jar\
  -files mapper,reducer\
  -input $INPUT_PATH\
  -output $OUTPUT_PATH\
  -mapper mapper\
  -reducer reducer