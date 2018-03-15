#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000001
#define MOD 1000000007
using namespace std;
int a[N];
int n;
long long f[N],ni[N];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
long long C(int x,int y){
	return f[x]*ni[y]%MOD*ni[x-y]%MOD;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	f[0]=1;
	for (int i=1;i<=n;i++)f[i]=f[i-1]*i%MOD;
	ni[n]=calc(f[n],MOD-2);
	for (int i=n-1;i>=0;i--)ni[i]=ni[i+1]*(i+1)%MOD;
	int l=1;
	for (int i=2;i<=n+1;i++)
		if (i==n+1||a[i]!=a[i-1]){
			if (l==1)
				l=i;
			else{
				ans=ans*C(l-1+i-l,i-l)%MOD*f[i-l]%MOD;
				for (int j=1;j<=i-l;j++)
					(ans+=f[l-1]*C(l-1+i-l-j-1,i-l-j)%MOD*f[i-l]%MOD*a[i-1]%MOD)%=MOD;
				l=i;
			}
		}
	printf("%d",(int)ans);
	return 0;
}
