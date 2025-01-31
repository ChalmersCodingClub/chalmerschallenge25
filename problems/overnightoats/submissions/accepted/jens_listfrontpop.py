#!/usr/bin/python3
n = int(input())
x = int(input())

v = []
for i in range(n):
    s = input()
    if s == 'ADD':
        v.append(i)
    if v and i - v[0] > x:
        print("ono..")
        exit(0)
    elif s == 'EAT':
        t = v.pop(0)
print("yay!")