#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10001;
const ll MOD=1e9+7;
ll ans[N*2];
ll a[N],b[N*2],c[N];
int n;
ll ni2;
ll calc(ll x,ll y){
	ll s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
ll C2(ll x){
	return x*(x-1)%MOD;
}
int main(){
	//freopen("h.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n;
	a[1]=1;
	for (int i=2;i<=n;i++)
		cin>>c[i],a[i]=a[i-1]*c[i]%MOD;	
	ni2=calc(2,MOD-2);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (j==i)(b[i+j]+=a[j]*a[i]%MOD*ni2%MOD)%=MOD;
			else
				(b[i+j]+=a[j]*a[i]%MOD)%=MOD;
	for (int i=1;i<=n;i++){
		ll v=a[i]*calc(a[i+1],MOD-2)%MOD*calc(a[i+1],MOD-2)%MOD;
		for (int j=i;j<=n;j++)
			if (j==i)
				(b[j+i]+=MOD-a[i]*a[j]%MOD*ni2%MOD)%=MOD;
			else
				(b[j+i]+=MOD-a[i]*a[j]%MOD)%=MOD;
		for (int j=i+i;j<=n+n;j++)
			(ans[j-i-i]+=b[j]*v%MOD*C2(c[i+1])%MOD)%=MOD;
		for (int j=i+1;j<=n;j++)
			(ans[j-i]+=a[j])%=MOD;
		/*for (int j=i+1;j<=n;j++){
			for (int k=j;k<=n;k++){
				if (j==k){
					(ans[j-i+k-i]+=v*a[i+2][j]%MOD*a[i+2][k]%MOD*ni2%MOD*C2(a[i+1][i+1])%MOD)%MOD;
				}else
					(ans[j-i+k-i]+=v*a[i+2][j]%MOD*a[i+2][k]%MOD*C2(a[i+1][i+1])%MOD)%MOD;
			}
			(ans[j-i]+=v*a[i+1][j]%MOD)%=MOD;
		}*/
	}
	for (int i=1;i<=n*2-2;i++)
		cout<<ans[i]<<' ';
	return 0;
}
