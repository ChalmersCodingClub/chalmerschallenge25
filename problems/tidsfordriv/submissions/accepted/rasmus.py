#!/usr/bin/python3
n={i:4for i in"23456789JQKA"}
n["10"]=4
for i in range(int(input())):
  c=input()
  l=c[0]
  if len(c)==3:l+=c[1]
  n[l]-=1
_=n.values()
print(max(_)/sum(_))
