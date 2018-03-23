#include<bits/stdc++.h>
#define N 100000
using namespace std;
typedef long long ll;
int T;
int n,m;
int d[N];
ll b[N];
int*l[16];
ll gcd(ll a,ll b){
	return !a?b:gcd(b%a,a);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
bool check(int x){
	bool sig=0;
	while (x)sig^=1,x-=(x&(-x));
	return sig;
}
void dfs(int* d,int x,int y,int z,int v){
	d[x]+=v;
	while (y<z){
		if (!(x&(1<<y)))
			dfs(d,x+(1<<y),y+1,z,-v);
		y++;
	}
}
void pre(){
	l[1]=&d[0];
	for (int i=2;i<=15;i++)
		l[i]=(l[i-1])+(1<<(i-1));
	for (int i=1;i<=15;i++)
		for (int j=1;j<(1<<i);j++)
			if (check(j)){
				dfs(l[i],j,0,i,1);
			}
	for (int i=1;i<=15;i++){
		int*d=l[i];
		for (int j=1;j<(1<<i);j++)
			cout<<d[j]<<' ';
		cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	pre();
	cin>>T;
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=m;i++)
			cin>>b[1<<(i-1)];
 		int*d=l[m];
 		ll ans=0;
 		for (int i=1;i<(1<<m);i++){
 			if (i!=(i&(-i))){
 				b[i]=min(lcm(b[i-(i&(-i))],b[i&(-i)]),(ll)n+1);	
 			}
 			ans+=d[i]*(n/b[i]);
 		}
 		cout<<ans<<endl;
	}
	return 0;
}
