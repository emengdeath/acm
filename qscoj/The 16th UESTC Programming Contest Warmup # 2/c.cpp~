#include<bits/stdc++.h>
#define N 2000
using namespace std;
int v[N],s[N],f[N];
int n,m,k;
bool check(int L){
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
		if (v[i]>=L)
			for (int j=m-s[i];j>=0;j--)
				f[j+s[i]]=max(f[j+s[i]],f[j]+v[i]);
	for (int i=0;i<=m;i++)
		if (f[i]>=k)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)cin>>s[i]>>v[i];
	int l=0,r=1e6,mid,s=-1;
	while (l<=r){
		if (check(mid=(l+r)/2))s=max(s,mid),l=mid+1;
		else
			r=mid-1;
	}
	cout<<s;
	return 0;
}
