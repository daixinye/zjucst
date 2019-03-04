import sys

def main(s):
    s = list(s)

    result = ""
    for c in s:
        result += c if c not in result else ''
    print(len(result))

main(input())
