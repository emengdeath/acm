#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
long long f[N][20];
int fa[N][20];
long long ans;
int n;
int help[20];
int main(){
	int Q;
	scanf("%d",&Q);
	n=1;
	help[0]=1;
	for (int i=1;i<20;i++)help[i]=help[i-1]*2;
	while (Q--){
		int sig;
		long long r,x;
		scanf("%d %I64d %I64d",&sig,&r,&x);
		r^=ans,x^=ans;
		if (sig==1){
			++n;
			//fa[++n][0]=r;
			for (int i=19;i>=0;i--)
				while (f[fa[r][i]][0]<x&&fa[r][i])r=fa[r][i];
			if (f[r][0]<x)r=fa[r][0];
			f[n][0]=x;
			if (f[r][0]>=x)fa[n][0]=r;
			for (int i=0;fa[fa[n][i]][i]&&f[fa[n][i]][0]>=x;i++)
				fa[n][i+1]=fa[fa[n][i]][i],f[n][i+1]=f[n][i]+f[fa[n][i]][i];
		}else{
			ans=0;
			for (int i=19;i>=0;i--)
				while (f[r][i]<=x&&fa[r][i]){
					x-=f[r][i];
					ans+=help[i];
					r=fa[r][i];
				}
			if (r&&f[r][0]<=x)ans++;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
