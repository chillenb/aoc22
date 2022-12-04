#!/usr/bin/env python3
import sys
ans = 0
with open(sys.argv[1]) as f:
    while True:
        line1, line2, line3 = f.readline(), f.readline(), f.readline()
        if "" == line1:
            break
        common = set.intersection(set(line1.strip()), set(line2.strip()), set(line3.strip()))
        i = ord(list(common)[0])
        if i <= ord('Z') and i >= ord('A'):
            ans += i - ord('A') + 27
        elif i <= ord('z') and i >= ord('a'):
            ans += i - ord('a') + 1
print(ans)
