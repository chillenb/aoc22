#!/usr/bin/env python3
from aocd import get_data, submit
from collections import defaultdict
class Directory:
    def __init__(self, parent):
        self.parent = parent
        self.subdirs = {}
        self.files = 0
        self.total = None
    def du(self):
        self.total = self.files + sum(map(lambda d: d.du(), self.subdirs.values()))
        return self.total
    def sumbelow10k(self):
        return sum(map(lambda d: d.sumbelow10k(), self.subdirs.values())) + \
            sum([x.total for x in self.subdirs.values() if x.total <= 100000])
    def szs(self):
        return sum(map(lambda d: d.szs(), self.subdirs.values()), [self.total])

ses = get_data(day=7, year=2022).splitlines()
root = cur = Directory(None)
i = 0
while i < len(ses):
    spl = ses[i].split(" ")
    if spl[1] == "cd":
        cur = cur.parent if spl[2] == ".." else cur.subdirs.setdefault(spl[2], Directory(cur))
    elif spl[1] == "ls":
        while i + 1 < len(ses) and not ses[i+1].startswith("$"):
            dat = ses[i+1].split(" ")
            if dat [0] != "dir":
                cur.files += int(dat[0])
            i += 1
    i += 1
root.du()
print("Part 1:", root.sumbelow10k())
print("Part 2:", min(filter(lambda x: x >= (30000000 - (70000000 - root.total)), root.szs())))