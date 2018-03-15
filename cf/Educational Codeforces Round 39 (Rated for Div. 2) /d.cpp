#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
int n,m,k;
int f[2][N],a[N];
int c[N];
int main(){
//	freopen("c.in","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	bool bz=0,bz1=1;
	f[0][0]=1;
	for (int i=1;i<=n;i++,swap(bz,bz1)){
		int all=0;
		a[0]=1e9;
		for (int j=1;j<=m;j++){
			char cc;
			scanf(" %c",&cc);
			c[j]=cc;
			if (c[j]=='1')all++;
			c[j]=c[j]-'0'+c[j-1],a[j]=1e9;
		}
		for (int j=1;j<=m;j++)
			for (int l=j;l<=m;l++)
				a[all-(c[l]-c[j-1])]=min(a[all-(c[l]-c[j-1])],l-j+1);
		a[all]=0;
		for (int j=0;j<=k;j++)
			if (f[bz][j]){
				for (int l=0;l+j<=k&&l<=m;l++)
					if (a[l]!=1e9){
						if (f[bz1][j+l]==0||f[bz1][j+l]>f[bz][j]+a[l])
							f[bz1][j+l]=a[l]+f[bz][j];
					}
				f[bz][j]=0;
			}
	}
	int ans=1e9;
	for (int i=0;i<=k;i++)
		if (f[bz][i])
		ans=min(f[bz][i],ans);
	printf("%d\n",ans-1);
	return 0;
}
