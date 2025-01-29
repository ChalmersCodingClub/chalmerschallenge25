#!/bin/usr/python3

n = int(input())
h = int(input())
positive = []
negative = []
for _ in range(n):
    x, y = map(int, input().split())
    if x < 0:
        negative.append((-x, y))
    else:
        positive.append((x, y))
positive.sort()
negative.sort()

s = 0
k = float('inf')
for x, y in positive:
    if (y - h) / x < k:
        s += 1
        k = (y - h) / x

k = float('inf')
for x, y in negative:
    if (y - h) / x < k:
        s += 1
        k = (y - h) / x

print(s)
