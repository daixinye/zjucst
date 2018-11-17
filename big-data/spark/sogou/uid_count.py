from pyspark import SparkContext

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.map(lambda line: line.split('\t')[1])
rdd = rdd.distinct()
print(rdd.count())