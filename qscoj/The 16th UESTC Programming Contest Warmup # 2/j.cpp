#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50001;
int n;
int g[N][16];
struct Node{
	int mx;
	ll sum;
	Node(int MX=0,ll SUM=0){mx=MX,sum=SUM;}
	ll calc(){
		return sum-mx;
	}
};
struct Seg{
	Node l,all;
}f[N][16],d;
Node operator+(const Node&a,const Node&b){
	return Node(max(a.mx,b.mx),a.sum+b.sum);
}
Seg operator+(Seg&a,Seg&b){
	Seg c;
	c.all=a.all+b.all;
	Node d=a.all+b.l;
	if (d.calc()>a.l.calc())c.l=d;
	else
		c.l=a.l;
	return c;
}
int gcd(int x,int y){
	return !x?y:gcd(y%x,x);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>g[i][0];
	int x=n;
	n=0;
	for (int i=1;i<=x;i++)
		if (g[i][0])g[++n][0]=g[i][0];
	for (int i=1;i<=n;i++){
		f[i][0].l=f[i][0].all=Node(g[i][0],g[i][0]);
		g[i][0]=abs(g[i][0]);
	}
	for (int i=1;i<16;i++)
		for (int j=1;j+(1<<i)<=n+1;j++){
			g[j][i]=gcd(g[j][i-1],g[j+(1<<(i-1))][i-1]);
			f[j][i]=f[j][i-1]+f[j+(1<<(i-1))][i-1];
		}
	ll ans=0;
	for (int i=1;i<=n;i++){
		int l=i+1,j;
		int Gcd=g[i][0];
		d=f[i][0];
		while (l<=n){
			if (!g[l][0])break;
			Gcd=gcd(Gcd,g[l][0]);
			j=15;
			while (j>=0&&l<=n){
				while (j>=0&&(gcd(g[l][j],Gcd)<Gcd||l+(1<<j)>n+1))j--;
				if (j>=0){
					d=d+f[l][j];
					l+=(1<<j);
				}
			}
			ans=max(ans,d.l.calc()*Gcd);
		}
	}
	cout<<ans;
	return 0;
}
