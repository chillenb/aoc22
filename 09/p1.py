#!/usr/bin/env python3
import sys

dmap = {'U': (0, 1), 'D': (0, -1), 'L': (-1, 0), 'R': (1, 0)}
def axpy(a, b, c): # return a + c(b)
    return (a[0]+c*b[0], a[1]+c*b[1])
def move(hloc, tloc, d):
    revh = axpy(hloc, d, -1)
    if tloc == revh or tloc == axpy(revh, d[::-1], 1) or tloc == axpy(revh, d[::-1], -1):
        tloc = hloc
    return axpy(hloc, d, 1), tloc

t = h = (0,0)
tlocs = {t}
with open(sys.argv[1]) as f:
    for line in f.readlines():
        d, s = line.split(" ")
        for i in range(int(s)):
            h, t = move(h, t, dmap[d])
            tlocs.add(t)
print(len(tlocs))