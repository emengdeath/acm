#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
#define MOD 1000000007
using namespace std;
int n,mx,tomx;
long long a[N],ni[N];
int s[N],sum[N];
long long ans[N],ans1[N];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
long long C(int x,int y){
	return a[x]*ni[y]%MOD*ni[x-y]%MOD;
}
int main(){
	scanf("%d",&n);
	a[0]=1;
	for (int i=1;i<N;i++)a[i]=a[i-1]*i%MOD;
	ni[N-1]=calc(a[N-1],MOD-2);
	for (int i=N-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%MOD;
	for (int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	int x=n;
	n=1,sum[1]=1;
	mx=1,tomx=1;
	for (int i=2;i<=x;i++){
		if (s[i]==s[n])sum[n]++;
		else{
			s[++n]=s[i];
			sum[n]=1;
		}
		if (sum[n]>=mx)mx=sum[n],tomx=n;
	}
	long long v=1;
	for (int i=tomx-1;i>=1;i--)
		(v*=C(mx,sum[i])*a[sum[i]]%MOD)%=MOD;
	for (int i=tomx+1;i<=n;i++)
		(v*=C(mx,sum[i])%MOD*a[sum[i]]%MOD)%=MOD;
	printf("%d",v);
	return 0;
}
