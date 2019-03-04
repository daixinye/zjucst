import sys

def main(num):
    num = list(num)
    num.reverse()

    result = ""
    for c in num:
        result += c if c not in result else ''
    print(result)

main(input())
