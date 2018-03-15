#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
using namespace std;
int sum[N];
long long v[N];
long long f[N];
long long bb[N];
int bz[N];
long long ans;
int tot;
long long a,b,p,x;
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=p;
		(x*=x)%=p,y/=2;
	}
	return s;
}
int main(){
	scanf("%I64d %I64d %I64d %lld",&a,&b,&p,&x);
	long long aa=1;
	for (int i=1;i<=p;i++)
		(aa*=a)%=p,sum[v[i]=i*aa%p]++;
	aa=calc(aa,p-2);
	/*while (x>=p){
		ans+=sum[b];
		b=b*aa%p;
		x-=p;
	}*/
	while (!bz[b]){
		bb[bz[b]=++tot]=b;
		f[tot]=f[tot-1]+sum[b];
		(b*=aa)%=p;
	}
	long long c=x/p;
	ans=f[tot]*(c/tot)+f[c%tot];
	x%=p;
	b=bb[c%tot+1];
	for (int i=1;i<=x;i++)
		if (v[i]==b)ans++;
	printf("%I64d\n",ans);
	return 0;
}
