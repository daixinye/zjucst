from pyspark import SparkContext
import re

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.filter(lambda line: re.match(".*\/$",line.split("\t")[5]))
print("Index Count:", rdd.count())