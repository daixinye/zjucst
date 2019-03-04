import sys
import math

def main(numStr):
    num = float(numStr)
    num = math.floor(num + 0.5)

    print(num)

main(input())
