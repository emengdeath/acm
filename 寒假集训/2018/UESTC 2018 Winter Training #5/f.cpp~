#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
#define MOD 1000000007
using namespace std;
long long f[N][N][3];
int n,k,sum,ans;
int g[N],a[N][2];
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x,int fa){
	f[x][1][1]=1;
	f[x][0][0]=1;
	for (int i=g[x];i;i=a[i][1]){
		if (a[i][0]==fa)continue;
		dfs(a[i][0],x);
		int y=a[i][0];
		for (int j=k;j>=0;j--){
			long long a[3];
			a[0]=a[1]=a[2]=0;
			for (int l=0;l<=j;l++){
				(a[0]+=f[x][l][0]*((f[y][j-l][0]+f[y][j-l][2])%MOD)%MOD)%=MOD;
				(a[1]+=f[x][l][1]*f[y][j-l][0]%MOD)%=MOD;
				(a[2]+=f[x][l][1]*((f[y][j-l][1]+f[y][j-l][2])%MOD)%MOD+f[x][l][2]*((f[y][j-l][1]+f[y][j-l][0]+f[y][j-l][2])%MOD)%MOD)%=MOD;
			}
			f[x][j][0]=a[0],f[x][j][1]=a[1],f[x][j][2]=a[2];
		}
	}
}
int main(){
	//freopen("f.in","r",stdin);
	while (scanf("%d %d",&n,&k)!=EOF){
		sum=0;
		for (int i=1;i<=n;i++)g[i]=0;
		for (int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			ins(x,y),ins(y,x);
		}
		for (int i=1;i<=n;i++)
			for (int j=0;j<=k;j++)f[i][j][0]=f[i][j][1]=f[i][j][2]=0;
		dfs(1,0);
		printf("%d\n",(int)(f[1][k][0]+f[1][k][2])%MOD);
	}
	return 0;
}
