#!/usr/bin/python3
n,m = map(int,input().split())
a = []
for _ in range(n):
    name, pos = input().split()
    a.append((int(pos), 1 + (name in ("Joshua", "Gustav"))))
b = [tuple(map(int, input().split())) for _ in range(m)]
a.sort()
b.sort()
i = 0
cnt = 0
for p, c in a:
    while i < m and p > b[i][1]:
        i += 1
    if i >= m or b[i][0] > p:
        cnt += c
print(cnt)
    
