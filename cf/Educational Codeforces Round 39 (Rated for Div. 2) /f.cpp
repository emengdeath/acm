#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 201
#define MOD 1000000007
using namespace std;
long long f[N][N][N],g[N][N][N],w[N][N][N],sum[N];
int n,x;
char s[N+2];
int main(){
	scanf("%d %d",&n,&x);	
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='0')w[0][i][i]++;
		else
			w[1][i][i]++;
	f[0][0][0]=f[1][0][0]=2;
	for (int i=2;i<=x;i++){
		f[i][0][0]=(long long)f[i-1][0][0]*f[i-2][0][0]%MOD;
		(sum[i]=(long long)sum[i-1]*f[i-2][0][0]%MOD+(long long)sum[i-2]*f[i-1][0][0]%MOD)%=MOD;
		for (int j=1;j<=n;j++)
			for (int k=j;k<=n;k++){
				if (j==1&&k==n)
					(sum[i]+=(long long)(f[i-1][j][k]+g[i-1][j][k]+w[i-1][j][k])%MOD*f[i-2][0][0]%MOD+(long long)(f[i-2][j][k]+g[i-2][j][k]+w[i-2][j][k])%MOD*f[i-1][0][0]%MOD)%=MOD;
				else{
					g[i][j][k]=((long long)(g[i-1][j][k]+w[i-1][j][k])%MOD*((f[i-2][0][0]+MOD-1)%MOD)%MOD+g[i-1][j][k]+g[i-2][j][k])%MOD;
					(f[i][j][k]=f[i-1][j][k]+(long long)f[i-2][j][k]*f[i-1][0][0]%MOD+(long long)w[i-2][j][k]*((f[i-1][0][0]+MOD-1)%MOD)%MOD)%=MOD;
					w[i][j][k]=(w[i-1][j][k]+w[i-2][j][k])%MOD;
				}
			}
		for (int j=1;j<=n;j++)
			for (int k=j;k<=n;k++)
				for (int l=k+1;l<=n;l++){
					(f[i][j][l]+=(long long)f[i-1][j][k]*w[i-2][k+1][l]%MOD)%=MOD;
					(g[i][j][l]+=(long long)w[i-1][j][k]*g[i-2][k+1][l]%MOD)%=MOD;
					(w[i][j][l]+=(long long)w[i-1][j][k]*w[i-2][k+1][l]%MOD)%=MOD;
					if (j==1&&l==n)(sum[i]+=(long long)f[i-1][j][k]*g[i-2][k+1][l]%MOD)%=MOD;
				}
	}
	printf("%d\n",(f[x][1][n]+g[x][1][n]+sum[x]+w[x][1][n])%MOD);
	return 0;
}
