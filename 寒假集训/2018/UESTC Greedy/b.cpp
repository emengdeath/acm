#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 200000
using namespace std;
int a[N*2][2],g[N],in[N],size[N],mx;
int n,sum,ans;
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x,int fa){
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa){
			dfs(a[i][0],x);
			if (size[a[i][0]]&1)ans+=1;
			else
				ans+=2;
			size[x]+=size[a[i][0]];
		}
}
void dfs1(int x,int fa,int v){
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa){
			if (size[a[i][0]]&1)
				dfs1(a[i][0],x,v-1);
			else
				dfs1(a[i][0],x,v+1);
		}
	mx=max(mx,v);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		sum=1;
		for (int i=1;i<=n;i++)size[i]=in[i]=g[i]=0;
		ans=0;
		for (int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			ins(x,y),ins(y,x);
			in[x]++,in[y]++;
		}
		int s=0;
		for (int i=1;i<=n;i++)
			if (in[i]==1)s=i,size[i]=1;
			else
				size[i]=0;
		size[s]=0;
		dfs(s,0);
		mx=0;
		dfs1(s,0,0);
		(size[s]&1)?printf("%d\n",ans):printf("%d\n",ans-mx);
	}
	return 0;
}
