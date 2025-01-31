g = int(input())
n = int(input())
p = 2
for i in range(n):
    a, b = map(int, input().split())
    if p in [a,b]: p^=a^b
if g==p:
    print(*{1,2,3}-{g})
else:
    print(g, p)
