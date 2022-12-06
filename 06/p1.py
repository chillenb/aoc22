#!/usr/bin/env python3
from aocd import get_data, submit
data = get_data(day=6, year=2022)
for i in range(len(data)-3):
    if len(set(data[i:i+4])) == 4:
        print(i+4)
        submit(i+4, part="a", day=6, year=2022)
        break
