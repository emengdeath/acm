#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000001
using namespace std;
int dis[N];
long long a[N*20][3];
int l[N],r[N];
int n,m,tot;
void update(int x,int y){
	a[++tot][0]=x,a[tot][1]=y;
}
void dfs(int x){
	if (x>n)return;
	dfs(x+x),dfs(x+x+1);
	int u=x+x,v=x+x+1;
	int l1,l2;
	int r1,r2;
	if (u>n)l1=1,r1=0;
	else
		l1=l[u],r1=r[u];
	if (v>n)l2=1,r2=0;
	else
		l2=l[v],r2=r[v];
	l[x]=tot+1;
	update(0,1);
	while (l1<=r1||l2<=r2){
		if (l1<=r1){
			if (l2<=r2){
				if (a[l1][0]+dis[u]==a[l2][0]+dis[v]){
					update(a[l1][0]+dis[u],a[l1][1]+a[l2][1]);
					l1++,l2++;
				}else
				if (a[l1][0]+dis[u]<a[l2][0]+dis[v]){
					update(a[l1][0]+dis[u],a[l1][1]),l1++;
				}else
					update(a[l2][0]+dis[v],a[l2][1]),l2++;
			}else{
				update(a[l1][0]+dis[u],a[l1][1]),l1++;
			}
		}else{
			update(a[l2][0]+dis[v],a[l2][1]);
			l2++;
		}
	}
	r[x]=tot;
}
long long er(int l,int r,int v){
	int mid,s=l;
	if (a[l][0]>v)return 0;
	while (l<=r){
		if (a[mid=(l+r)/2][0]<=v)l=mid+1,s=max(s,mid);
		else
			r=mid-1;
	}
	return v*a[s][1]-a[s][2];
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=2;i<=n;i++)
		scanf("%d",&dis[i]);
	dfs(1);
	for (int i=1;i<=n;i++){
		a[l[i]][2]=a[l[i]][0]*a[l[i]][1];
		for (int j=l[i]+1;j<=r[i];j++){
			a[j][2]=a[j-1][2]+a[j][0]*a[j][1];
			a[j][1]+=a[j-1][1];
		}
	}
	while (m--){
		int x,y;
		long long ans=0;
		scanf("%d %d",&x,&y);
		int yy=y;
		while (1){
			ans+=er(l[x],r[x],y);
			y-=dis[x];
			if (x==1)break;
			if (y<=0)break;
			if (x!=1){
				ans-=er(l[x],r[x],y-dis[x]);
			}
			x=x/2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
