#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 400000
using namespace std;
int v[N],g[N],a[N*4][2];
bool instack[N];
int stack[N],belong[N];
int dfn[N],low[N],in[N],gg[N],num[N];
bool bz[N];
int n,m,h,sum,top;
int next(int x){
	return (x+1)%h;
}
bool one(int x,int y){
	return next(x)==y;
}
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void ins1(int x,int y){
	a[++sum][0]=y,a[sum][1]=gg[x],gg[x]=sum;
}
void dfs(int x){
	static int calc=0;
	dfn[x]=low[x]=++calc,stack[++stack[0]]=x,instack[x]=1;
	for (int i=g[x];i;i=a[i][1])
		if (!dfn[a[i][0]]){
			dfs(a[i][0]);
			low[x]=min(low[x],low[a[i][0]]);
		}else
			if (instack[a[i][0]])
				low[x]=min(low[x],dfn[a[i][0]]);
	if (low[x]==dfn[x]){
		++top;
		do{
			num[top]++;
			instack[stack[stack[0]]]=0;
			belong[stack[stack[0]]]=top;
			ins1(top,stack[stack[0]]);
			in[stack[stack[0]--]]=top;
		}while (stack[stack[0]+1]!=x);
	}
	return;
}
int main(){
	scanf("%d %d %d",&n,&m,&h);
	for (int i=1;i<=n;i++)scanf("%d",&v[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if (one(v[x],v[y]))ins(x,y);
		if (one(v[y],v[x]))ins(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])dfs(i);
	for (int i=1;i<=n;i++)
		for (int j=g[i];j&&!bz[belong[i]];j=a[j][1])
			if (belong[a[j][0]]!=belong[i])
				bz[belong[i]]=1;
	int x=-1;
	for (int i=1;i<=top;i++)
		if (!bz[i]&&(x==-1||num[x]>num[i]))x=i;
	printf("%d\n",num[x]);
	for (int i=gg[x];i;i=a[i][1])
		printf("%d ",a[i][0]);
	return 0;
}
