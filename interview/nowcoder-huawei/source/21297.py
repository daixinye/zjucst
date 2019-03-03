line = input()

stack = []
result = []
isQuot = False

for char in line:
    if char == "\"":
        if isQuot:
            if len(stack):
                result.append(stack.)

print(result)
