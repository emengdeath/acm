#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
using namespace std;
int n,x;
double p,f[N];
int main(){
	int T;
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d %lf %d",&n,&p,&x);
		for (int i=1;i<=n;i++)f[i]=(f[i-1]+1)/(1-p);
		double ans=f[n]+x;
		for (int i=1;i<=n;i++){
			int a=n/i;
			int b=n%i;
			ans=min(ans,i*x+f[a]*(i-b)+f[a+1]*b);
		}
		printf("%.6f\n",ans);
	}
	return 0;
}
