#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int N=1e5+13;
int n,q,L,R,mx;
int a[N*2][2],g[N],d[N],b[N],size[N],mxsize[N],fa[N][18],deep[N];
bool bz[N];
ll ni2;
ll sum[N],sum1[N],fsum[N];
int v[N];
void ins(int x,int y){
	static int sum=0;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum; 
}
void dfs(int x,int fa){
	size[x]=1;
	mxsize[x]=0;
	d[++d[0]]=x;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa&&!bz[a[i][0]]){
			dfs(a[i][0],x);
			size[x]+=size[a[i][0]];
			mxsize[x]=max(size[a[i][0]],mxsize[x]);
		}
}
int getroot(int x){
	d[0]=0;
	dfs(x,0);
	x=d[1];
	for (int i=2;i<=d[0];i++)
		if (max(d[0]-size[x],mxsize[x])>max(d[0]-size[d[i]],mxsize[d[i]]))x=d[i];
	return x;
}
inline ll get(int l,int r){
	r=min(r,mx);
	if (l>=r||r<0)return 0;
	return l<=-1?b[r]:b[r]-b[l];
}
void dfs(int x,int fa,int len,int sig){
	switch(sig){
		case 0:	
		b[len]++;
		mx=max(mx,len);
		break;
		case 1:
		(sum1[x]+=get(L-len,R-len))%=MOD;
		break;
		case 2:
		(sum1[x]+=MOD-get(L-len,R-len))%=MOD;
		break;
	}
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa&&!bz[a[i][0]])
			dfs(a[i][0],x,len+1,sig);
}
void dfs1(int x,int fa){
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa&&!bz[a[i][0]]){
			dfs1(a[i][0],x);
			(sum1[x]+=sum1[a[i][0]])%=MOD;
		}
}
void dfs(int x){
	x=getroot(x);
	bz[x]=1;
	for (int i=1;i<=d[0];i++)
		b[i]=0,sum1[d[i]]=0;
	mx=0;
	b[0]=1;
	for (int i=g[x];i;i=a[i][1])
		if (!bz[a[i][0]])
			dfs(a[i][0],x,1,0);	
	for (int i=1;i<=mx;i++)
		b[i]+=b[i-1];
	(sum1[x]+=get(L,R))%=MOD;
	for (int i=g[x];i;i=a[i][1])
		if (!bz[a[i][0]])
			dfs(a[i][0],x,1,1);	
	for (int i=g[x];i;i=a[i][1])
		if (!bz[a[i][0]]){
			for (int j=0;j<=mx;j++)b[j]=0;
			mx=0;
			dfs(a[i][0],x,1,0);
			for (int j=1;j<=mx;j++)b[j]+=b[j-1];
			dfs(a[i][0],x,1,2);		
		}
	dfs1(x,0);
	(sum1[x]*=ni2)%=MOD;
	for (int i=1;i<=d[0];i++)
		(sum[d[i]]+=sum1[d[i]])%=MOD;
	for (int i=g[x];i;i=a[i][1])
		if (!bz[a[i][0]])
			dfs(a[i][0]);
}
void dfs1(int x){
	for (int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	deep[x]++;
	(fsum[x]+=sum[x])%=MOD;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa[x][0]){
			fa[a[i][0]][0]=x;
			deep[a[i][0]]=deep[x];
			fsum[a[i][0]]=fsum[x];
			dfs1(a[i][0]);
		}
}
int getlca(int x,int y){
	int i=17;
	if (deep[x]<deep[y])swap(x,y);
	while (deep[x]!=deep[y]){
		while (deep[fa[x][i]]<deep[y])i--;
		x=fa[x][i];
	}
	i=17;
	while (x!=y){
		while (i&&fa[x][i]==fa[y][i])i--;
		x=fa[x][i],y=fa[y][i];
	}
	return x;
}
ll calc(ll x,ll y){
	ll s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(false);
	ni2=calc(2,MOD-2);
	cin>>n>>q>>L>>R;
	if (L==0)
		for (int i=1;i<=n;i++)sum[i]=1;
	else
		L--;
	for (int i=1;i<=n;i++)cin>>v[i];
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		ins(x,y),ins(y,x);
	}
	dfs(1);
	ll ans=0;
	for (int i=1;i<=n;i++)
		(ans+=v[i]*sum[i]%MOD)%=MOD;
	dfs1(1);
	while (q--){
		int u,v,z;
		cin>>u>>v>>z;
		int lca=getlca(u,v);
		(ans+=z*((fsum[u]+fsum[v]+(MOD-fsum[lca])*2+sum[lca])%MOD)%MOD)%=MOD;
		cout<<ans<<endl;
	}
	return 0;
}
