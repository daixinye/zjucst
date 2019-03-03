import sys 
for line in sys.stdin:
    def triangle(depth):
        if depth == 1:
            return [1]
        elif depth == 2:
            return [1,1,1]
        elif depth == 3:
            return [1,2,3,2,1]
        else:
            prev = [0,0]+triangle(depth-1)+[0,0]
            result = []
            for i in range(depth*2-1):
                result.append(prev[i]+prev[i+1]+prev[i+2])
            return result.copy()

    n = int(line)
    result = -1

    for i, v in enumerate(triangle(n)):
        if v %2  == 0:
            result = i+1
            break
    print(result)