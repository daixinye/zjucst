from pyspark import SparkContext

sc = SparkContext('local', 'test')
rdd = sc.textFile("/sogou/20111230/sogou.500w.utf8")

rdd = rdd.map(lambda line: (line.split('\t')[1],1))
rdd = rdd.reduceByKey(lambda a,b : a + b)

def mapper(line):
    count = line[1]
    if count < 5:
        return ("0-5",1)
    elif count < 10:
        return ("5-10",1)
    elif count < 50:
        return ("10-50",1)
    elif count < 100:
        return ("50-100",1)
    elif count < 500:
        return ("100-500",1)
    else:
        return ("500+",1)

rdd = rdd.map(mapper).reduceByKey(lambda a,b:a+b).sortByKey()

for rg,count in rdd.collect():
    print(rg,count)
