#!/usr/bin/env python3
import sys
ans = 0
with open(sys.argv[1]) as f:
    for line in f.readlines():
        range1, range2 = line.strip().split(',')
        range1 = [int(x) for x in range1.split('-')]
        range2 = [int(x) for x in range2.split('-')]
        if range1[0] <= range2[0] and range2[1] <= range1[1]:
            ans += 1
        elif range2[0] <= range1[0] and range1[1] <= range2[1]:
            ans += 1
print(ans)
