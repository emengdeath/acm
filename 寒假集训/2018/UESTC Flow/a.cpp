#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
#define MAXN 100000000
#include<cmath>
#include<cstring>
using namespace std;
int n,m,t,flow,sum,p;
bool bz[N],map[N][N];
int g[N],dis[N],d[N],pre[N],w[N],v[N];
long long a[N*N][4];
void ins(int x,int y,int z,long long zz){
	a[++sum][0]=y,a[sum][1]=z,a[sum][2]=zz,a[sum][3]=g[x],g[x]=sum;
	a[++sum][0]=x,a[sum][1]=0,a[sum][2]=-zz,a[sum][3]=g[y],g[y]=sum;
}
bool spfa(){
	static int l,r;
	d[1]=l=0,r=1;
	for (int i=1;i<=t+1;i++)
		dis[i]=MAXN;
	bz[0]=1;
	while (l!=r){
		for (int i=g[d[l=l%t+1]];i;i=a[i][3])
			if (a[i][1]&&a[i][2]+dis[d[l]]<dis[a[i][0]]){
				dis[a[i][0]]=a[i][2]+dis[d[l]];
				pre[a[i][0]]=i;
				if (!bz[a[i][0]])
					d[r=r%t+1]=a[i][0],bz[a[i][0]]=1;
			}
		bz[d[l]]=0;
	}
	return dis[t]!=MAXN;
}
bool cost(){
	int x;
	long long cost=0; 
	while (spfa()){
		flow++;
		x=t;
		cost+=dis[t];
		if (cost>=p)return 1;
		while (x){
			a[pre[x]][1]--;
			a[pre[x]^1][1]++;
			x=a[pre[x]^1][0];
		}
	}
	return 0;
}
int main(){
	freopen("a.in","r",stdin);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			char c;
			scanf(" %c",&c);
			if (c=='1')map[i][j]=1;
		}
	for (int i=1;i<=n;i++)scanf("%d",&w[i]);
	for (int i=1;i<=m;i++)scanf("%d",&v[i]);
	scanf("%d",&p);
	t=n+m+1;
	int ans=0;
	for (int i=1;i<(1<<n);i++){
		sum=1;
		for (int j=0;j<=t;j++)g[j]=0;
		for (int j=1;j<=n;j++)
			if (i&(1<<(j-1)))ins(0,j,1,0);
		for (int j=1;j<=m;j++)
			ins(j+n,t,1,0);
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				if (map[j][k])ins(j,k+n,1,(long long)w[j]*v[k]);
		ans+=cost();
	}
	printf("%d\n",ans);
	return 0;
}
