#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
#define MOD 1000000007
using namespace std;
int n;
long long b[N];
struct node{
	int x,y;
}a[N];
long long calc(long long x,long long y){
	long long s=1;
	x%=MOD;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
long long ni(long long x){
	return calc(x,MOD-2);
}
long long C(int x,int y){
	return b[x]*ni(b[y])%MOD*ni(b[x-y])%MOD;
}
bool cmp(const node&a,const node&b){
	return a.y>b.y;
}
int main(){
	freopen("input","r",stdin);
	scanf("%d",&n);
	b[0]=1;
	for (int i=1;i<=n;i++)b[i]=(long long)b[i-1]*i%MOD;
	long long ans=0,all=b[n-2];
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x].y++;
		a[x].x=x;
		(all*=ni(b[x-1]))%=MOD;
	}
	sort(a+1,a+N,cmp);
	for (int i=1;i<=n;i++)
		if (!a[i].y)break;
		else
		for (int j=1;j<=n;j++)
		if (!a[j].y)break;
		else{
			long long v=all;
			long long x=a[i].x,y=a[j].x;
			if (x<4||y<3)continue;
			v=v*b[x-1]%MOD*b[y-1]%MOD*ni(b[x+y-3])%MOD*C(x+y-2,x-1)%MOD;
			if (x==y){
				if (a[i].y<2)continue;
				(ans+=v*C(x-1,3)%MOD*C(y-1,2)%MOD*a[i].y%MOD*(a[i].y-1)%MOD)%=MOD;
			}else
				(ans+=v*C(x-1,3)%MOD*C(y-1,2)%MOD*a[i].y%MOD*a[j].y%MOD)%=MOD;
		}
	(ans*=ni(all*(n-2)%MOD))%=MOD;
	printf("%d\n",(int)ans);
	return 0;
}
