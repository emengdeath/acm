#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
const ll MOD=1e9+7;
int n,m,k;
int a[N],b[N];
string S;
ll s[N],t[N],help[N];
ll get(ll*s,int l,int r){
	return (s[r]-s[l-1]*help[r-l+1]%MOD+MOD)%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	cin>>S;
	for (int i=1;i<=n;i++)
		s[i]=(s[i-1]*27+S[i-1]-'a'+1)%MOD;
	cin>>S;
	for (int i=1;i<=m;i++)
		t[i]=(t[i-1]*27+S[i-1]-'a'+1)%MOD;
	help[0]=1;
	for (int i=1;i<N;i++)help[i]=help[i-1]*27%MOD;
	for (int i=1;i<=n;i++){
		int l=1,r=min(n-i+1,m),mid,v=0;
		while (l<=r){
			mid=(l+r)/2;
			if (get(s,i,i+mid-1)==get(t,1,mid))v=max(v,mid),l=mid+1;
			else
				r=mid-1;
		}
		if (v)a[v+i-1]=max(a[v+i-1],v);
	}
	for (int i=n-1;i>=1;i--)
		a[i]=max(a[i],a[i+1]-1);
	for (int i=1;i<=n;i++){
		int l=1,r=min(i,m),mid,v=0;
		while (l<=r){
			mid=(l+r)/2;
			if (get(s,i-mid+1,i)==get(t,m-mid+1,m))v=max(v,mid),l=mid+1;
			else
				r=mid-1;
		}
		if (v)b[i-v+1]=max(b[i-v+1],v);
	}
	for (int i=2;i<=n;i++)
		b[i]=max(b[i],b[i-1]-1);
	int x=0;
	for (int i=n;i>=1;i--){
		if (i-k+1>=1&&a[i]+b[x]>=m&&a[i]+b[x]-m<=i-k+(n-x+1)-k&&x){
			cout<<"Yes"<<endl;
			while (a[i]+b[x]-m){
				if (i>k)i--;
				else
					x++;
			}
			cout<<i-k+1<<' '<<x<<endl;
			return 0;
		}
		if (i+k-1<=n&&b[i]>b[x])x=i;
	}
	cout<<"No";
	return 0;
}
