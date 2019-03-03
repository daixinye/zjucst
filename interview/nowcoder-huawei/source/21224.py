import sys
import re

for line in sys.stdin:
    pattern = "([a-zA-Z]+$)"
    match = re.search(pattern, line).groups()
    s = match[0]
    print(len(s))
