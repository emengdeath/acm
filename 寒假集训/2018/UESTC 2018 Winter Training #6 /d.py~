import math
maxn=1e18+1;
T=0
def calc2(x):
	x=(x+3)*x//2
	if x>maxn:
		return maxn
	else:
		return x
def calc(x,y):
	if (y==0):
		return 1
	x+=y-1
	y=x-y
	s=1
	for i in range(1,y+1):
		s*=x-i+1
	for i in range(1,y+1):
		s//=i;
	if s>maxn:
		return maxn
	else:
		return s
while (1):
	n,k=map(int,raw_input().split())
	if (n==0) and (k==0):
		break;
	T+=1
	print "Case %d:" %(T),
	if (k==0):
		for i in range(n):
			print " 0",
		print
	elif n==1:
		print "%d" %(k)
	elif n==2:
		l=1
		r=int(math.sqrt(k)*2)
		mid=0
		s=0
		while (l<=r):
			mid=(l+r)//2;
			if (calc2(mid)<k):
				l=mid+1
				s=max(s,mid)
			else:
				r=mid-1;
		k-=calc2(s);
		s+=1
		print "%d %d" %((k-1),(s-(k-1)))
	else:
		x=1
		z=0
		while (1):
			z=calc(n,x)
			if z>=k:
				break
			k-=z
			x+=1
		for i in range(1,n):
			y=0;
			while (1):
				z=calc(n-i,x-y);
				if (z>=k):
					break;
				k-=z
				y+=1
			x-=y
			print "%d" %(y),
		print "%d" %(x);
