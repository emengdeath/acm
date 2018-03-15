#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000
#include<cstring>
using namespace std;
int v[N][N];
int n,m;
bool bz,bz1;
int f[2][N],b[N];
int main(){
	freopen("e.in","r",stdin);
	int T;
	scanf("%d",&T);
	bz=0,bz1=1;
	while (T--){
		scanf("%d %d",&n,&m);
		memset(f,0,sizeof(f));
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&v[i][j]);
		f[bz][0]=1;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (x>0){
				b[0]=1,b[1]=x;
			}else{
				b[0]=m;
				for (int j=1;j<=m;j++)b[j]=j;
			}
			for (int j=0;j<=m;j++)
				if (f[bz][j]){
					for (int k=1;k<=b[0];k++)
						f[bz1][b[k]]=max(f[bz1][b[k]],f[bz][j]+v[j][b[k]]);
					f[bz][j]=0;
				}
			bz^=1,bz1^=1;
		}
		int ans=0;
		for (int i=1;i<=m;i++)
			ans=max(f[bz][i],ans);
		printf("%d\n",ans-1);
	}
	return 0;
}
