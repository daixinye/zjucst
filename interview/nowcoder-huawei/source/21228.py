import sys

def main(arg):
    print(eval(arg))

while True:
    try:
        main(input())
    except:
        break
