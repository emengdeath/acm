#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int N=1e3+12;
const ll V=2323323;
ll f[N][N],g[N][N],help[N],help1[N];
int n,m,q;
ll get(ll*f,int l,int r){
	return (f[r]-f[l-1]*help[r-l+1]%MOD+MOD)%MOD;
}
int main(){
	//freopen("f.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			char c;
			cin>>c;
			f[i][j]=g[j][i]=c-'0';
		}
	help[0]=1;
	help1[0]=1;
	for (int i=1;i<N;i++)help[i]=help[i-1]*2%MOD,help1[i]=help1[i-1]*V%MOD;
	for (int i=1;i<=n;i++)
		for (int j=2;j<=m;j++)
			(f[i][j]+=f[i][j-1]*2)%=MOD;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			(f[i][j]+=f[i-1][j]*V%MOD)%=MOD;
	for (int i=1;i<=m;i++)
		for (int j=2;j<=n;j++)
			(g[i][j]+=g[i][j-1]*2)%=MOD;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			(g[i][j]+=g[i-1][j]*V%MOD)%=MOD;
	cin>>q;
	while (q--){
		int x0,y0,x1,y1,x2,y2,x3,y3;
		cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
		++x0,++y0;
		++x1,++y1;
		++x2,++y2;
		++x3,++y3;
		int sum=1;
		int l=0,r=x1-x0;
		if (l==r)sum=(((get(f[x0],y0,y1)-get(f[x0-1],y0,y1)*help1[1]%MOD+MOD)%MOD)!=(get(f[x2],y2,y3)-get(f[x2-1],y2,y3)*help1[1]%MOD+MOD)%MOD);
		while (l<r){
			int mid=(l+r)/2;
			bool sig=(((get(f[x0+mid],y0,y1)-get(f[x0+l-1],y0,y1)*help1[mid-l+1]%MOD+MOD)%MOD)!=(get(f[x2+mid],y2,y3)-get(f[x2+l-1],y2,y3)*help1[mid-l+1]%MOD+MOD)%MOD);
			bool sig1;
			if (mid==r)sig1=0;
			else sig1=(((get(f[x0+r],y0,y1)-get(f[x0+mid],y0,y1)*help1[r-mid]%MOD+MOD)%MOD)!=(get(f[x2+r],y2,y3)-get(f[x2+mid],y2,y3)*help1[r-mid]%MOD+MOD)%MOD);
			if (sig&&sig1){
				sum=2;
				break;
			}
			if (!sig&&!sig1){
				sum=0;
				break;
			}
			if (sig)r=mid;
			else
				l=mid+1;
		}
		if (sum>1){
			cout<<"Wrong"<<endl;
			continue;
		}
		if (!sum){
			cout<<"Perfect"<<endl;
			continue;
		}
		sum=1;
		l=0,r=y1-y0;
		if (l==r)sum=(((get(g[y0],x0,x1)-get(g[y0-1],x0,x1)*help1[1]%MOD+MOD)%MOD)!=(get(g[y2],x2,x3)-get(f[y2-1],x2,x3)*help1[1]%MOD+MOD)%MOD);
		while (l<r){
			int mid=(l+r)/2;
			bool sig=(((get(g[y0+mid],x0,x1)-get(g[y0+l-1],x0,x1)*help1[mid-l+1]%MOD+MOD)%MOD)!=(get(g[y2+mid],x2,x3)-get(g[y2+l-1],x2,x3)*help1[mid-l+1]%MOD+MOD)%MOD);
			bool sig1;
			if (mid==r)sig1=0;
			else sig1=(((get(g[y0+r],x0,x1)-get(g[y0+mid],x0,x1)*help1[r-mid]%MOD+MOD)%MOD)!=(get(g[y2+r],x2,x3)-get(g[y2+mid],x2,x3)*help1[r-mid]%MOD+MOD)%MOD);
			if (sig&&sig1){
				sum=2;
				break;
			}
			if (!sig&&!sig1){
				sum=0;
				break;
			}
			if (sig)r=mid;
			else
				l=mid+1;
		}
		sum==1?cout<<"One difference"<<endl:cout<<"Wrong"<<endl;
	}
	return 0;
}


