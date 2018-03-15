n=int(input())
m=int(input())
a=[]
b=[]
for i in range(1,n+1):
	a[i]=int(input())
for i in range(1,m+1):
	b[i]=int(input())
ans=99;
for i in range(1,n+1):
	for j in range(1,m+1):
		v=99;
		if (a[i]==b[j]):
			v=a[i]
		elif (a[i]>b[j]):
			v=a[i]+b[j]*10
		else:
			v=a[i]*10+b[j]
		if (ans>v):
			ans=v
print(ans)
