#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
using namespace std;
struct node{
	int x,y;
}a[N];
int n,m;
int x[N],y[N],to[N],sum[N];
long long ans;
bool cmp(const node&a,const node&b){
	return a.x<b.x;
}
int er(int x){
	int l=1,r=y[0],mid;
	while (l<=r){
		mid=(l+r)/2;
		if (y[mid]==x)return mid;
		else
		if (y[mid]<x)l=mid+1;
		else
			r=mid-1;
	}
	if (y[l]==x)return l;
	return r;
}
void work(){
	for (int i=1;i<=n;i++)x[i]=a[i].x,y[i]=a[i].y;
	sort(a+1,a+n+1,cmp);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	x[0]=y[0]=1;
	for (int i=2;i<=n;i++){
		if (x[i]!=x[x[0]])x[++x[0]]=x[i];
		if (y[i]!=y[y[0]])y[++y[0]]=y[i];
	}
	for (int i=1;i<=n;i++)
		to[i]=er(a[i].y);
	for (int i=1;i<=y[0];i++)sum[i]=0;
	int all=0,l=1,r=y[0];
	for (int i=1;i<=x[0];i++){
		int xx=x[i];
		while (l<=n&&a[l].x<=xx)all+=(a[l].y<=y[r]),sum[to[l]]++,l++;
		while (all-sum[r]>=n/2)all-=sum[r],r--;
		if (all==n/2)ans=min(ans,(long long)(x[i]+1)*(y[r]+1));
	}
}
int main(){
	//freopen("g.in","r",stdin);
	while (scanf("%d %d",&m,&n)!=EOF){
		ans=(long long)m*m;
		for (int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].y);
		if (n&1){
			printf("-1\n");
			continue;
		}
		work();
		for (int i=1;i<=n;i++)
			a[i].x=m-a[i].x-1;
		work();
		for (int i=1;i<=n;i++)
			a[i].y=m-a[i].y-1;
		work();
		for (int i=1;i<=n;i++)
			a[i].x=m-a[i].x-1	;
		work();
		ans!=(long long)m*m?printf("%I64d\n",ans):printf("-1\n");//I64d!!!
	}
	return 0;
}
