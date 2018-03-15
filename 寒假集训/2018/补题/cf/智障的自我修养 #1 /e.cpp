#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
#define MOD 1000000007
using namespace std;
int a[N],b[N];
int n,m;
long long calc(long long x,long long y){
	long long s=1;
	x%=MOD;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
	long long P=0,Q,S=1;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	int sum=0;
	for (int i=1;i<=n;i++){
		sum+=(!a[i]);
		sum+=(!b[i]);
	}
	long long all=(long long)m*(m-1)/2%MOD;
	Q=calc(m,sum);
	for (int i=1;i<=n;i++){
		if (!a[i]){
			if (!b[i]){
				(P+=all*S%MOD*calc(m,sum-2)%MOD)%=MOD;
				(S*=m)%=MOD;
				sum-=2;
			}else{
				(P+=(m-b[i])*S%MOD*calc(m,sum-1)%MOD)%=MOD;
				sum--;
			}
		}else{
			if (!b[i]){
				(P+=(a[i]-1)*S%MOD*calc(m,sum-1)%MOD)%=MOD;
				sum--;
			}else{
				if (a[i]<b[i]){
					break;
				}else
				if (a[i]>b[i]){
					(P+=S*calc(m,sum)%MOD)%=MOD;
					break;
				}
			}
		}		
		if (P<0)return 0;
	}
	int ans=P*calc(Q,MOD-2)%MOD;
	printf("%d\n",ans);
	return 0;
}
