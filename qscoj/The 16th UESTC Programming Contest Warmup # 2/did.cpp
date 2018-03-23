#include<bits/stdc++.h>
#define N 1000000
using namespace std;
typedef unsigned long long ll;
ll ans;
int a[N];
int n;
int gcd(int x,int y){
	return !x?y:gcd(y%x,x);
}
int main(){
//	freopen("j.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		int mx=a[i];
		ll all=a[i];
		if (!a[i])continue;
		int Gcd=abs(a[i]);
		for (int j=i+1;j<=n;j++)
			if (!a[j])break;
			else{
				mx=max(a[j],mx);
				all+=a[j];
				Gcd=gcd(Gcd,abs(a[j]));
				ans=max(ans,(all-mx)*Gcd);
			}
	}
	cout<<ans;
	return 0;
}
