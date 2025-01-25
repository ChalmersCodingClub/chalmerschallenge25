i,c=input,{x:4for x in'123456789AJQK'}
n=int(i())
exec('c[i()[0]]-=1;'*n)
print(max(c.values())/(52-n))