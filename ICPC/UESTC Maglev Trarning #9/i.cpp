#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define M 600
#define N 100000
#include<cmath>
using namespace std;
long long a[N][M],C[M][M],b[N][M];
int n,T,k;
int main(){
	freopen("i.in","r",stdin);
	scanf("%d",&T);
	C[0][0]=1;
	for (int i=1;i<M;i++){
		C[i][0]=1;		
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	a[0][0]=1;
	b[0][0]=1;
	while (T--){
		scanf("%d %d",&n,&k);
		long long all=0;
		for (int i=1;i<=n;i++){
			char c;
			scanf(" %c",&c);
			c-='0';
			(all+=c)%=MOD;
			long long v=1;
			for (int j=0;j<=k;j++)
				a[i][j]=v,(v*=all)%=MOD;
			b[i][0]=i+1;
			for (int j=1;j<=k;j++)
				b[i][j]=(b[i-1][j]+a[i][j])%MOD;
		}
		for (int i=1;i<=n;i++){
			long long v=0,sig=1;
			for (int j=0;j<=k;j++,sig*=-1)
				(v+=b[i-1][j]*sig*a[i][k-j]%MOD*C[k][j]%MOD)%=MOD;
			(v+=MOD)%=MOD;
			if (i==1)printf("%lld",v);
			else
				printf(" %lld",v);
		}
		printf("\n");
	}
	return 0;
}
