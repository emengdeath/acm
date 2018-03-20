#include<bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long ll;
ll a[N],b[N],c[N];
int n;
int get(int l,int r,int s,ll x,ll y){
	if (c[r]<x||y<c[l])return 0;
	if (x<=c[l]&&c[r]<=y)return r-l+1;
	return get(l,(l+r)/2,s+s,x,y)+get((l+r)/2+1,r,s+s+1,x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i];
	ll ans=0;
	for (unsigned long long i=1;i<(1<<30);i<<=1){
		for (int j=1;j<=n;j++)c[j]=b[j]%(i<<1);
		sort(c+1,c+n+1);
		bool sig=0;
		ll l1=i,r1=(i<<1)-1,l2=i+(i<<1),r2=(i<<2)-1;
		for (int j=1;j<=n;j++){
			ll v=a[j]%(i<<1);
			sig^=((get(1,n,1,l1-v,r1-v)+get(1,n,1,l2-v,r2-v))&1);
		}
		ans+=sig*i;
	}
	cout<<ans;
	return 0;
}
