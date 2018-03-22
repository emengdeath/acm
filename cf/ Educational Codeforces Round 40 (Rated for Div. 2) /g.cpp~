#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000000;
ll a[N],b[N];
int n,R;
ll k;
bool check(ll limit){
	for (int i=0;i<=n;i++)
		b[i]=0;
	ll K=k;
	for (int i=1;i<=n;i++){
		b[i]+=b[i-1];
		ll v=b[i]+a[i];
		if (v<limit){
			v=limit-v;
			if (v>K)return 0;
			K-=v;
			b[i]+=v;
			b[min(i+R+R+1,n+1)]-=v;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>R>>k;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[max(i-R,0)]+=x;
		a[min(i+R+1,n+1)]-=x;
	}
	for (int i=1;i<=n;i++)
		a[i]+=a[i-1];
	ll l=0,r=2e18,mid,s=0;
	while (l<=r){
		if (check(mid=(l+r)/2))l=mid+1,s=max(s,mid);
		else
			r=mid-1;
	}
	cout<<s;
	return 0;
}
