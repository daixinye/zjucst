import sys


def main(n):
    n = int(n)
    obj = {}
    for i in range(n):
        line = input()
        k, v = tuple(line.split())
        k = int(k)
        v = int(v)
        if k in obj:
            obj[k] = obj[k] + v
        else:
            obj[k] = v
    for k, v in sorted(obj.items(),reverse = False):
        print(k, v)


main(input())
