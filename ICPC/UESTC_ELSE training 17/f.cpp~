#include<iostream>
#include<algorithm>
#include<cstdio>
#define MOD 1000000007
using namespace std;
int n,m,k,T;
long long ans;
long long ni[1000001];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
	scanf("%d",&T);
	ni[1000000]=1;
	for (int i=1;i<=1000000;i++)
		(ni[1000000]*=i)%=MOD;
	ni[1000000]=calc(ni[1000000],MOD-2);
	for (int i=999999;i>=0;i--)
		ni[i]=ni[i+1]*(i+1)%MOD;
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d %d %d",&n,&m,&k);
		long long x=1;
		ans=0;
		for (int i=1;i<=k;i++){
			(x*=(k-i+1))%=MOD;
			if ((i&1)==(k&1))(ans+=x*ni[i]%MOD*i%MOD*calc(i-1,n-1)%MOD)%=MOD;
			else
				(ans+=MOD-x*ni[i]%MOD*i%MOD*calc(i-1,n-1)%MOD)%=MOD;
		}
		x=1;
		for (int i=1;i<=k;i++)
			(x*=m-i+1)%=MOD;
		ans=ans*x%MOD*ni[k]%MOD;
		printf("%I64d\n",ans);
	}
	return 0;
}
