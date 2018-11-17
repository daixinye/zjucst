from pyspark import SparkContext

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.map(lambda line: (line.split('\t')[4],1))
rdd = rdd.reduceByKey(lambda a,b : a + b)
rdd = rdd.map(lambda line : (line[1], line[0])).sortByKey(False)

for count,rank in rdd.collect():
    print(rank, count)