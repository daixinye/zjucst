from pyspark import SparkContext
sc = SparkContext('local', 'test')

sogou_data = sc.textFile("file:///home/hadoop/github/zjucst/big-data/spark/testFile/sogou.txt")
sogou_data = sogou_data.map(lambda line: line.split('\t'))

kv = sogou_data.map(lambda line: (line[2],1))
kv = kv.reduceByKey(lambda a,b: a+b)
kv.foreach(print)