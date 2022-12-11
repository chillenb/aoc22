#!/usr/bin/env python3
import sys
dmap = {'U': (0, 1), 'D': (0, -1), 'L': (-1, 0), 'R': (1, 0)}
def sign(x):
    return 0 if x == 0 else x//abs(x)
def axpy(a, b, c): # return a + c(b)
    return (a[0]+c*b[0], a[1]+c*b[1])
def find_dir(hloc, tloc, d):
    diff = axpy(axpy(hloc, d, 1), tloc, -1)
    if diff[0]**2+diff[1]**2 > 2:
        return (sign(diff[0]), sign(diff[1]))
    return (0,0)

rope = [(0,0) for i in range(10)]
tlocs = {(0,0)}
with open(sys.argv[1]) as f:
    for line in f.readlines():
        d, s = line.split(" ")
        for i in range(int(s)):
            sdir = dmap[d]
            for knot in range(9):
                nd = find_dir(rope[knot], rope[knot+1], sdir)
                rope[knot] = axpy(rope[knot], sdir, 1)
                sdir = nd
            rope[9] = axpy(rope[9], nd, 1)
            tlocs.add(rope[9])
print(len(tlocs))

