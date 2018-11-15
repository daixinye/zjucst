from pyspark import SparkContext
sc = SparkContext('local', 'test')

sogou_data = sc.textFile("/sogou/20111230/sogou.500w.utf8")
print(sogou_data.first())

