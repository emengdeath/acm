#include<iostream>
#include<algorithm>
#include<cstdio>
#define MOD 1000000007
using namespace std;
int f[27],sum[10];
int n;
long long ans;
long long a[100000],ni[100000];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
void update(int x){
	while (x)sum[x%10]++,x/=10;
}
void calc(){
	int all=0;
	long long s=1;
	for (int i=1;i<=9;i++)all+=sum[i],(s*=ni[sum[i]])%=MOD;
	for (int i=10;i<=26;i++)all+=f[i],(s*=ni[f[i]])%=MOD;
	(ans+=s*a[all]%MOD)%=MOD;
}
void dfs(int x){
	if (x==20)x++;
	if (x==27){
		calc();
		return;
	}
	int xx=x/10,yy=x%10;
	for (int i=0;i<=min(sum[xx],sum[yy]);i++){
		sum[xx]-=i;
		sum[yy]-=i;
		f[x]=i;
		dfs(x+1);
		sum[xx]+=i;
		sum[yy]+=i;
	}
	f[x]=0;
}
int main(){
	a[0]=1;
	for (int i=1;i<100000;i++)a[i]=a[i-1]*i%MOD;
	ni[99999]=calc(a[99999],MOD-2);
	for (int i=99998;i>=0;i--)ni[i]=ni[i+1]*(i+1)%MOD;
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<10;i++)sum[i]=0;
		for (int i=2;(long long)i*i<=n;i++)
			while (!(n%i))update(i),n/=i;
		if (n!=1)update(n);
		ans=0;
		for (int i=0;i<=sum[0];i++)
		if (sum[1]>=i&&sum[2]>=sum[0]-i){
			sum[1]-=i;
			sum[2]-=sum[0]-i;
			f[10]=i;
			f[20]=sum[0]-i;
			dfs(11);
			sum[1]+=i;
			sum[2]+=sum[0]-i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
