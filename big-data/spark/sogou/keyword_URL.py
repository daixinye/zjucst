from pyspark import SparkContext
import re

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.filter(lambda line: re.match("www",line.split('\t')[2]))

print("URL as Keyword:", rdd.count())