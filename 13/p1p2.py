#!/usr/bin/env python3
import sys
from functools import cmp_to_key

def compare(l, r):
    if type(l)==int and type(r)==int:
        return -1*(l>r)+1*(l<r)
    elif type(l)==list and type(r)==int:
        return compare(l, [r])
    elif type(l)==int and type(r)==list:
        return compare([l], r)
    else:
        for a, b in zip(l, r):
            x = compare(a,b)
            if x != 0:
                return x
        return compare(len(l),len(r))
        
i = 1
ans = 0
pkts = []
with open(sys.argv[1]) as f:
    while True:
        line = f.readline()
        if not line:
            break
        line1 = eval(line.strip())
        line2 = eval(f.readline().strip())
        pkts.append(line1)
        pkts.append(line2)
        ans += (compare(line1, line2) == 1)*1
        i += 1
        f.readline()
print(ans)
pkts.extend([[[2]],[[6]]])
pkts.sort(key=cmp_to_key(compare), reverse=True)
prod = 1
for i, x in enumerate(pkts):
    if x == [[2]] or x == [[6]]:
        prod = prod * (i+1)
print(prod)