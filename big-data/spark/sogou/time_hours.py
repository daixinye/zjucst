from pyspark import SparkContext

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.map(lambda line: (line.split('\t')[0][8:10],1))
rdd = rdd.reduceByKey(lambda a,b: a+b).sortByKey()

for hour, count in rdd.collect():
    print(hour,count)