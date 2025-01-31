from collections import deque

n = int(input())
x = int(input())

bad = False
q = deque()
for i in range(n):
    s = input()
    if s == 'ADD':
        q.appendleft(i)
    if s == 'EAT':
        t = q.pop() # vad händer om det inte finns någon?
        if t+x < i:
            bad = True
# vad händer om q inte är tom nu?
if bad:
    print("ono..")
else:
    print("yay!")
