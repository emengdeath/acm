#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 2000000
using namespace std;
int d[N+1],in[N];
long long dis[N];
int g[N],g1[N],tag[N],dfn[N],low[N],stack[N];
long long a[N*4][3];
long long ans[N],v[N],help[N];
bool instack[N],bz[N];
int sum,n,m,calc,tot,s;
void ins(int x,int y,int z,int*g){
	a[++sum][0]=y,a[sum][1]=z,a[sum][2]=g[x],g[x]=sum;
}
long long get(long long x){
	long long s=sqrt(x*2);
	while (s*(s+1)/2>x)s--;
	while ((s+1)*(s+2)/2<=x)s++;
	return x*(s+1)-help[s];
}
void dfs(int x){
	instack[x]=1,stack[++stack[0]]=x,dfn[x]=low[x]=++calc;
	for (int i=g[x];i;i=a[i][2])
		if (!dfn[a[i][0]]){
			dfs(a[i][0]);
			low[x]=min(low[x],low[a[i][0]]);
		}else
		if (instack[a[i][0]])
			low[x]=min(low[x],dfn[a[i][0]]);
	if (low[x]==dfn[x]){
		++tot;
		do{
			tag[stack[stack[0]]]=tot;
			instack[stack[stack[0]--]]=0;
		}while (stack[stack[0]+1]!=x);
	}
}
void spfa(){
	int l=0,r=1;
	d[1]=tag[s];
	dis[tag[s]]=v[tag[s]];
	while (l!=r){
		for (int i=g1[d[++l]];i;i=a[i][2]){
				dis[a[i][0]]=max(dis[a[i][0]],dis[d[l]]+a[i][1]+v[a[i][0]]);
				if (!(--in[a[i][0]])){
					d[++r]=a[i][0];
				}
			}
	}
}
void dfs1(int x){
	for (int i=g1[x];i;i=a[i][2]){
		in[a[i][0]]++;
		if (in[a[i][0]]==1)dfs1(a[i][0]);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=100000;i++)
		help[i]=help[i-1]+(long long)i*(i+1)/2;
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		ins(x,y,z,g);
	}
	scanf("%d",&s);
	dfs(s);
	for (int i=1;i<=n;i++){
		for (int j=g[i];j;j=a[j][2])
			if (tag[a[j][0]]==tag[i])
				v[tag[i]]+=get(a[j][1]);
			else
				ins(tag[i],tag[a[j][0]],a[j][1],g1);
	}
	dfs1(tag[s]);
	spfa();
	long long ans=0;
	for (int i=1;i<=tot;i++)
		ans=max(ans,dis[i]);
	printf("%I64d\n",ans);
	return 0;
}
