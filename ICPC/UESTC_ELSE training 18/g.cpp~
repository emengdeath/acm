#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 400000
using namespace std;
struct node{
	int c,sum;
	int son[2];
	void clear(){
		son[0]=son[1]=0;
	}
}f[N*30];
struct E{
	int x,y,len;
}e[N];
int n,m,q,T,L;
int fa[N],fa1[N][17],len[N],g[N];
void build(int l,int r,int s,int c,int sum){
	f[s].c=c,f[s].sum=sum;
	if (l==r)return;
	if ((l+r)/2>=c){
		f[s].son[0]=++L;
		build(l,(l+r)/2,L,c,sum);
	}else{
		f[s].son[1]=++L;
		build((l+r)/2+1,r,L,c,sum);
	}
}
bool cmp(const E&a,const E&b){
	return a.len<b.len;
}
void combine (int l,int r,int x,int y,int z){
	if (l==r){
		f[z].c=l,f[z].sum=f[x].sum+f[y].sum;
		return;
	}
	if (f[x].son[0]){
		if (f[y].son[0]){
			f[z].son[0]=++L;
			combine(l,(l+r)/2,f[x].son[0],f[y].son[0],f[z].son[0]);
		}else f[z].son[0]=f[x].son[0];	
	}else
	if (f[y].son[0])f[z].son[0]=f[y].son[0];
	if (f[x].son[1]){
		if (f[y].son[1]){
			f[z].son[1]=++L;
			combine((l+r)/2+1,r,f[x].son[1],f[y].son[1],f[z].son[1]);
		}else f[z].son[1]=f[x].son[1];
	}else
	if (f[y].son[1])f[z].son[1]=f[y].son[1];
	if (f[f[z].son[0]].sum>=f[f[z].son[1]].sum)f[z].c=f[f[z].son[0]].c,f[z].sum=f[f[z].son[0]].sum;
	else
		f[z].c=f[f[z].son[1]].c,f[z].sum=f[f[z].son[1]].sum;
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int main(){
//	freopen("g.in","r",stdin);
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		scanf("%d %d",&n,&m);
		while (L){
			f[L--].clear();
		}
		for (int i=1;i<=n;i++){
			int c;
			scanf("%d",&c);
			build(1,1000000,g[i]=++L,c,1);
			fa[i]=i;
			len[i]=10000000;
		}
		for (int i=1;i<=m;i++)
			scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].len);
		sort(e+1,e+m+1,cmp);
		for (int i=1;i<=m;i++){
			int x=getfa(e[i].x),y=getfa(e[i].y);
			if (x!=y){
				fa1[x][0]=++n;
				fa1[y][0]=n;
				fa[n]=n;
				len[n]=10000000;
				len[y]=len[x]=e[i].len;
				combine(1,1000000,g[x],g[y],g[n]=++L);
				fa[x]=fa[y]=n;
			}
		}
		for (int i=1;i<=n;i++)
			for (int j=0;fa1[fa1[i][j]][j];j++)fa1[i][j+1]=fa1[fa1[i][j]][j];
		scanf("%d",&m);
		int ans=0;
		while (m--){
			int x,y;
			scanf("%d %d",&x,&y);
			x^=ans,y^=ans;
			for (int i=16;i>=0;i--)
				while (fa1[x][i]&&len[fa1[x][i]]<=y)x=fa1[x][i];
			while (fa1[x][0]&&len[x]<=y)x=fa1[x][0];
			ans=f[g[x]].c;
			printf("%d\n",ans);
		}
		for (int i=1;i<=n;i++)
			for (int j=0;j<=16;j++)fa1[i][j]=0;
	}
	return 0;
}
