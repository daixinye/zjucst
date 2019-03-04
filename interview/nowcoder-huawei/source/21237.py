import sys

def main(n):
    n = int(n)
    words = []
    for i in range(n):
        words.append(input())
    words = sorted(words)
    for word in words:
        print(word)


main(input())
