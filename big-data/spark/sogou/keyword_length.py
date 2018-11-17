from pyspark import SparkContext
sc = SparkContext('local', 'test')

rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")
count = rdd.count()

rdd = rdd.map(lambda line: len(line.split('\t')[2]))
average = rdd.reduce(lambda a,b:a+b) / count
maxLength = rdd.reduce(lambda a,b: a if a > b else b)
minLength = rdd.reduce(lambda a,b: a if a < b else b)

print("Average:", average)
print("Max Length:", maxLength)
print("Min Length:", minLength)