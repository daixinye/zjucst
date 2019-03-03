import sys

while True:
    try:
        n = int(sys.stdin.readline())
        dic = {}
        for i in range(n):
            dic[sys.stdin.readline()] = 1

        result = [int(i) for i in list(dic.keys())]
        result.sort()
        for val in result:
            print(val)
    except:
        break
