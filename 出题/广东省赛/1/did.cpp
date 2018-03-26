#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int N=1e5+13;
int n,q,L,R;
ll ans;
int v[N],a[N*2][2],g[N],fa[N],deep[N];
void ins(int x,int y){
	static int sum=0;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum; 
}
void dfs(int x){
	deep[x]++;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa[x]){
			fa[a[i][0]]=x;
			deep[a[i][0]]=deep[x];
			dfs(a[i][0]);
		}
}
void dfs(int x,int fa,int st,int len,ll va){
	(va+=v[x])%=MOD;
	if (R<len)return;
	if (L<=len&&st<=x)(ans+=va)%=MOD;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa)
			dfs(a[i][0],x,st,len+1,va);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q>>L>>R;
	for (int i=1;i<=n;i++)
		cin>>v[i];
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		ins(y,x),ins(x,y);
	}
	dfs(1);
	while (q--){
		int x,y,z;
		cin>>x>>y>>z;
		if (deep[x]<deep[y])swap(x,y);
		while (deep[x]!=deep[y]){
			(v[x]+=z)%=MOD;
			x=fa[x];
		}
		while (x!=y){
			(v[x]+=z)%=MOD,(v[y]+=z)%=MOD;
			x=fa[x],y=fa[y];
		}
		(v[x]+=z)%=MOD;
		ans=0;
		for (int i=1;i<=n;i++)
			dfs(i,0,i,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
