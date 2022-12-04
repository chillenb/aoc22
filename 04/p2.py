#!/usr/bin/env python3
import sys
ans = 0
with open(sys.argv[1]) as f:
    for line in f.readlines():
        range1, range2 = line.strip().split(',')
        range1 = [int(x) for x in range1.split('-')]
        range2 = [int(x) for x in range2.split('-')]
        lb = max(range1[0], range2[0])
        ub = min(range1[1], range2[1])
        if lb <= ub:
            ans += 1
print(ans)
