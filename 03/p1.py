#!/usr/bin/env python3
import sys
ans = 0
with open(sys.argv[1]) as f:
    for line in f.readlines():
        line = line.strip()
        n = len(line)
        common = set.intersection(set(line[:n//2]), set(line[n//2:]))
        i = ord(list(common)[0])
        if i <= ord('Z') and i >= ord('A'):
            ans += i - ord('A') + 27
        elif i <= ord('z') and i >= ord('a'):
            ans += i - ord('a') + 1
print(ans)
