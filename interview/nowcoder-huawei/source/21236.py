import sys

def main(sen):
    sen = sen.split()
    sen.reverse()
    
    print(" ".join(sen))

main(input())
