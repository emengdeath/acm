#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 10000
#define MOD 100000000
using namespace std;
const long long maxn=1e18+1;
int a[N];
int n;
long long k;
struct node{
	long long x[20];
	void turn(long long v){
		for (int i=1;i<20;i++)
			x[i]=v%MOD,v/=MOD;
	}
	long long toint(){
		long long v=0;
		for (int i=19;i;i--)
			v=v*MOD+x[i];
		return v;
	}
}e,maxn1;
bool operator>(node a,node b){
	for (int i=19;i;i--)
		if (a.x[i]!=b.x[i])
			return a.x[i]>b.x[i];
	return 0;
}
node operator+(node a,node b){
	for (int i=1;i<20;i++)
		a.x[i]+=b.x[i];
	for (int i=1;i<19;i++)
		a.x[i+1]+=a.x[i]/MOD,a.x[i]%=MOD;
	return a;
}
node operator+(node a,long long b){
	node s=e;
	s.turn(b);
	return a+s;
}
node operator/(node a,long long b){
	for (int i=19;i>=1;i--)
		a.x[i-1]+=MOD*(a.x[i]%b),a.x[i]/=b;
	return a;
}
node operator*(node a,node b){
	node s=e;
	for (int i=1;i<=19;i++)
		for (int j=1;j+i-1<=19;j++)
			s.x[i+j-1]+=a.x[i]*b.x[j];
	for (int i=1;i<19;i++)
		s.x[i+1]+=s.x[i]/MOD,s.x[i]%=MOD;
	return s;
}
node operator*(node a,long long b){
	for (int i=1;i<=19;i++)
		a.x[i]*=b;
	for (int i=1;i<19;i++)
		a.x[i+1]+=a.x[i]/MOD,a.x[i]%=MOD;
	return a;
}
long long calc2(long long x){
	node s=e;
	s.turn(x);
	s=(s+3)*s/2;
	return s>maxn1?maxn:s.toint();
}
long long calc(int x,int y){
	if (!y)return 1;
	x+=y-1;
	y=x-y;
	node s=e;
	s.x[1]=1;
	for (int i=1;i<=y;i++)
		s=s*(x-i+1);
	for (int i=1;i<=y;i++)s=s/i;
	return s>maxn1?maxn:s.toint();
}
int main(){
	int T=0;
	maxn1=e;
	maxn1.turn(maxn);
	while (1){
		int sss=scanf("%d%lld",&n,&k);
		if (!n&&!k)break;
		printf("Case %d:",++T);
		if (!k){
			for (int i=1;i<=n;i++)printf(" 0");
			printf("\n");
			continue;
		}
		if (n==1){
			printf(" %lld\n",k);
			continue;	
		}
		if (n==2){
			long long l=1,r=sqrt(k)*2,mid,s=0;
			while (l<=r){
				mid=(l+r)/2;
				if (calc2(mid)<k)l=mid+1,s=max(s,mid);
				else
					r=mid-1;
			}
			k-=calc2(s);
			s++;
			printf(" %lld %lld\n",k-1,s-(k-1));
			continue;
		}
		int x=1;
		long long z;
		while ((z=calc(n,x))<k)k-=z,x++;
		for (int i=1;i<n;i++){
			int y=0;
			while ((z=calc(n-i,x-y))<k){
				k-=z;
				y++;
			}
			x-=y;
			printf(" %d",y);
		}
		printf(" %d\n",x);
	}	
	return 0;
}
