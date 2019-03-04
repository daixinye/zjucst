import sys

def main(first, second):
    output(add(first))
    output(add(second))


def add(s):
    sList = list(s)
    length = len(sList)
    if length % 8 != 0:
        sList = sList + ['0']*(8-length % 8)

    sList = [sList[i:i+8] for i in range(0, len(sList), 8)]

    return sList


def output(sList):
    for val in sList:
        print(''.join(val))


while True:
    try:
        main(input(), input())
    except:
        break
