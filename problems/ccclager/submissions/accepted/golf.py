r,s,k=range,sorted,lambda:input().split()
n,m=map(int,k())
def q(_):a,b=k();return(int(b),1+(a in("Joshua","Gustav")))
i,c,x=0,0,s(map(q,r(n)))
h=[*s(list(map(int,k()))for _ in r(m))]
for p,d in x:
 while i<m and p>h[i][1]:i+=1
 if i>=m or h[i][0]>p:c+=d
print(c)
