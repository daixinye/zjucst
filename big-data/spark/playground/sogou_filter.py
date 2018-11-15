from pyspark import SparkContext
sc = SparkContext('local', 'test')

sogou_data = sc.textFile("file:///home/hadoop/github/zjucst/big-data/spark/testFile/sogou.txt")
sogou_data = sogou_data.filter(lambda line: 'baidu' in line)
count = sogou_data.count()
print(count)
sogou_data.foreach(print)