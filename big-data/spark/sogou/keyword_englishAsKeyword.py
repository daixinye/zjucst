from pyspark import SparkContext
import re

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.filter(lambda line: re.match("^[a-zA-Z ]$",line.split('\t')[2]))

print("English Keyword:", rdd.count())