#!/usr/bin/python3
from decimal import *
getcontext().prec = 200

n = int(input())

seen = {}
for i in range(n):
    card = input()[:-1]
    if card not in seen:
        seen[card]=0
    seen[card]+=1

if len(seen)<13:
    ans = Decimal(4)/Decimal(52-n)
else:
    ans = Decimal(4-min(seen.values()))/Decimal(52-n)
print(f"{ans:.15f}")
