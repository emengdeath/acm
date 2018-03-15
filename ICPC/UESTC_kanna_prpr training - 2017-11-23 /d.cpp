#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 500
#include<cstring>
using namespace std;
int a[N],b[N],c[N][2];
struct node{
	int l,r;
}x[N],y[N];
bool bz[N][N];
int T,R,C,n,m,top;
int fa[N*N];
long long sum[N*N];
long long ans[N*N];
void insert(node*a,int l,int r,int&n){
	if (l>r)return;
	a[++n].l=l,a[n].r=r;
}
int trans(int x,int y){
	return (x-1)*m+y;
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void combine(int x,int y){
	x=getfa(x),y=getfa(y);
	if (x==y)return;
	fa[x]=y;
	sum[y]+=sum[x];
	sum[x]=0;
}
int main(){
	freopen("d.in","r",stdin);
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		memset(bz,0,sizeof(bz));
		scanf("%d %d",&R,&C);
		scanf("%d",&top);
		if (!top){
			printf("1\n");
			printf("%I64d\n",(long long)R*C);
			continue;
		}
		for (int i=1;i<=top;i++){
			scanf("%d %d",&c[i][0],&c[i][1]);
			a[i]=c[i][0],b[i]=c[i][1];
		}
		sort(a+1,a+top+1);
		sort(b+1,b+top+1);
		a[0]=1;
		for (int i=1;i<=top;i++)
			if (a[a[0]]!=a[i])a[++a[0]]=a[i];
		b[0]=1;
		for (int i=1;i<=top;i++)
			if (b[b[0]]!=b[i])b[++b[0]]=b[i];
		n=0,m=0;
		insert(x,1,a[1]-1,n);	
		insert(y,1,b[1]-1,m);
		for (int i=1;i<a[0];i++){
			insert(x,a[i],a[i],n);
			insert(x,a[i]+1,a[i+1]-1,n);
		}
		for (int i=1;i<b[0];i++){
			insert(y,b[i],b[i],m);
			insert(y,b[i]+1,b[i+1]-1,m);
		}
		insert(x,a[a[0]],a[a[0]],n);
		insert(y,b[b[0]],b[b[0]],m);
		insert(x,a[a[0]]+1,R,n);
		insert(y,b[b[0]]+1,C,m);
		for (int i=1;i<=top;i++){
			int xx=1,yy=1;
			while (x[xx].l!=c[i][0])xx++;
			while (y[yy].l!=c[i][1])yy++;
			bz[xx][yy]=1;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				fa[trans(i,j)]=trans(i,j);
				if (bz[i][j])sum[trans(i,j)]=0;
				else
					sum[trans(i,j)]=(long long)(x[i].r-x[i].l+1)*(y[j].r-y[j].l+1);
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (!bz[i][j]){
					if (i>1&&!bz[i-1][j]){
						combine(trans(i-1,j),trans(i,j));
					}
					if (j>1&&!bz[i][j-1]){
						combine(trans(i,j-1),trans(i,j));
					}
				}
		ans[0]=0;
		for (int i=1;i<=n*m;i++)
			if (getfa(i)==i&&sum[i])
				ans[++ans[0]]=sum[i];
		sort(ans+1,ans+ans[0]+1);
		printf("%I64d\n",ans[0]);
		printf("%I64d",ans[1]);
		for (int i=2;i<=ans[0];i++)
			printf(" %I64d",ans[i]);
		printf("\n");
	}
	return 0;
}
