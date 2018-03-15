#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
int f[N],a[N],b[N],c[N];
int n,m;
int get(int l,int r,int s,int ll){
	if (r<=ll)return f[s];
	if (l>ll)return 0;
	return max(get(l,(l+r)/2,s+s,ll),get((l+r)/2+1,r,s+s+1,ll));
}
void ins(int l,int r,int s,int ll,int v){
	f[s]=max(f[s],v);
	if (l==r)
		return;
	if ((l+r)/2>=ll)ins(l,(l+r)/2,s+s,ll,v);
	else
		ins((l+r)/2+1,r,s+s+1,ll,v);
}
void build(int l,int r,int s){
	f[s]=0;
	if (l==r)return;
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
}
int main(){
	//freopen("c.in","r",stdin);
	scanf("%d %d",&n,&m);
	int nn=n;
	while (n--){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x]++,a[y+1]--;
	}
	n=nn;
	for (int i=1;i<=m;i++)a[i]+=a[i-1];
	for (int i=1;i<=m;i++)
		ins(0,n,1,a[i],b[i]=get(0,n,1,a[i])+1);
	build(0,n,1);
	for (int i=m;i>=1;i--)
		ins(0,n,1,a[i],c[i]=get(0,n,1,a[i])+1);
	for (int i=1;i<=m;i++)b[i]=max(b[i],b[i-1]);
	for (int i=m;i>=1;i--)c[i]=max(c[i],c[i+1]);
	int ans=0;
	for (int i=0;i<=m;i++)ans=max(ans,b[i]+c[i+1]);
	printf("%d\n",ans);
	return 0;
}
