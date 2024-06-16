# Non-random generator that requires many iteraions of while (1)-loop
from random import randint as rand
import random

n = int(1e5)
v = [i+1 for i in range(n)]
print(n)

buckets = [[] for i in range(5)]
for i in range(n):
    buckets[rand(0,4)].append(v[i])
for i in range(5):
    buckets[i] = buckets[i][::-1]
random.shuffle(buckets[0])
for i in range(n):
    u = rand(0, len(buckets)-1)
    print(buckets[u][-1])
    del buckets[u][-1]
    if len(buckets[u])==0:
        del buckets[u]
