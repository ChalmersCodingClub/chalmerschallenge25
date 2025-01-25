M = int(input())

edges = set()
deg = [0]*1000
for i in range(M):
    a,b = map(int, input().split())
    if a > b: a,b=b,a
    edges.add(a, b)
    deg[a] += 1
    deg[b] += 1

if max(deg) >= 38:
    print("seen before")
    exit()
print("not seen before")

u = 0
while deg[u] < 8:
    u += 1

v = -1
p = 0
while p < 30:
    v += 1
    if v == u: continue
    if (v,u) in edges or (u,v) in edges: continue
    print(u,v)
    p += 1
