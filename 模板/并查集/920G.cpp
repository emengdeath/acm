#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
using namespace std;
int n;
long long ans;
int fa[N],sum[N],g[N],a[N*2][2];
bool bz[N];
struct node{
	int x,y;
}b[N];
bool cmp(const node&a,const node&b){
	return a.x<b.x;
}
void ins(int x,int y){
	static int sum=1;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void clear(){
	for (int i=1;i<=n;i++)sum[i]=1,fa[i]=i,bz[i]=0;
}
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&b[i].x),b[i].y=i;
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ins(x,y),ins(y,x);
	}
	clear();
	for (int i=1;i<=n;i++){
		bz[b[i].y]=1;
		long long sum1=0;
		for (int j=g[b[i].y];j;j=a[j][1])
			if (bz[a[j][0]]){
				sum1+=(long long)sum[b[i].y]*sum[getfa(a[j][0])];
				sum[b[i].y]+=sum[getfa(a[j][0])];
				sum[getfa(a[j][0])]=0;
				fa[getfa(a[j][0])]=b[i].y;
			}
		ans+=(long long)b[i].x*sum1;
	}
	clear();
	for (int i=n;i>=1;i--){
		bz[b[i].y]=1;
		long long sum1=0;
		for (int j=g[b[i].y];j;j=a[j][1])
			if (bz[a[j][0]]){
				sum1+=(long long)sum[b[i].y]*sum[getfa(a[j][0])];
				sum[b[i].y]+=sum[getfa(a[j][0])];
				sum[getfa(a[j][0])]=0;
				fa[getfa(a[j][0])]=b[i].y;
			}
		ans-=(long long)b[i].x*sum1;
	}
	printf("%I64d\n",ans);
	return 0;
}
