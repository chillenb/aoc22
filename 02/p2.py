#!/usr/bin/env python3
import sys
score = 0
shape = {'X': 1, 'Y': 2, 'Z': 3}
win = {'A': 'Y', 'B': 'Z', 'C': 'X'}
lose = {'A': 'Z', 'B': 'X', 'C': 'Y'}
draw = {'A': 'X', 'B': 'Y', 'C': 'Z'}
new = {'X': lose, 'Y': draw, 'Z': win}
with open(sys.argv[1]) as f:
    for line in f.readlines():
        m1, m2 = line.split()
        d = new[m2]
        reqd = d[m1]
        if win[m1] == reqd:
            score += 6
        elif lose[m1] == reqd:
            score += 0
        else:
            score += 3
        score += shape[reqd]
print(score)