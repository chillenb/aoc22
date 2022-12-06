#!/usr/bin/env python3
from aocd import get_data, submit
data = get_data(day=6, year=2022)
for i in range(len(data)-13):
    if len(set(data[i:i+14])) == 14:
        print(i+14)
        submit(i+14, part="b", day=6, year=2022)
        break
