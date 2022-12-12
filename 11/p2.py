#!/usr/bin/env python3
import sys
mnid = 0
starting = []
op = []
test = []
iftrue = []
iffalse = []

def parse_term(arg, term):
    return arg if term == "old" else int(term)

def do_op(arg, operator):
    p1 = parse_term(arg, operator[0])
    p2 = parse_term(arg, operator[2])
    return p1 + p2 if operator[1] == "+" else p1 * p2

with open(sys.argv[1]) as f:
    while(f.readline()):
        starting.append([int(i) for i in f.readline().replace(",", " ").split()[2:]])
        op.append(tuple(f.readline().split()[-3:]))
        test.append(int(f.readline().split()[-1]))
        iftrue.append(int(f.readline().split()[-1]))
        iffalse.append(int(f.readline().split()[-1]))
        f.readline()

inspected = [0] * len(starting)
tprod = 1
for n in test:
    tprod *= n

for round in range(10000):
    for monkey in range(len(starting)):
        for item in starting[monkey]:
            inspected[monkey] += 1
            worry = do_op(item, op[monkey]) % tprod
            if worry % test[monkey] == 0:
                starting[iftrue[monkey]].append(worry)
            else:
                starting[iffalse[monkey]].append(worry)
        starting[monkey] = []

inspected = sorted(inspected)
print(inspected[-1] * inspected[-2])