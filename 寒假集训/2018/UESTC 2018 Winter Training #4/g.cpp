#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int f[N*4],a[N];
int n,v,T;
void build(int l,int r,int s){
	if (l==r){
		f[s]=a[l];
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s]=(f[s+s]|f[s+s+1]);
}
int get(int l,int r,int s,int ll,int rr){
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s];
	return (get(l,(l+r)/2,s+s,ll,rr)|get((l+r)/2+1,r,s+s+1,ll,rr));
}
int main(){
	freopen("wifi.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&v);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		build(1,n,1);
		int r=n;
		int ans=0;
		for (int i=n;i>=1;i--){
			while (get(1,n,1,i,r)>v)r--;
			ans=max(ans,r-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
