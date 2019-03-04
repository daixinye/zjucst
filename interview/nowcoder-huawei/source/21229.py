import sys

def main(num):
    result = []
    num = int(num)
    n = 2
    while n <= num:

        if num % n == 0:
            result.append(n)
            num = int(num / n)
        else:
            n = n + 1

    result = [str(i) for i in result]
    print(' '.join(result)+' ')

main(input())
