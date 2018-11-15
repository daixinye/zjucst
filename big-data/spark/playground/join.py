from pyspark import SparkContext
sc = SparkContext('local', 'test')
pair1 = sc.parallelize([('spark',1),('spark',2),('hadoop',1),('hadoop',2)])
pair2 = sc.parallelize([('spark',3)])
pair3 = pair1.join(pair2)
pair3.foreach(print)