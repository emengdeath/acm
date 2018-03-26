#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+23;
struct node{
	int sum;
	int son[2];
}tri[N*100];
struct node1{
	ll mn;
	int wz;
	void combine(const node1&a){
		if (a.mn<mn)mn=a.mn,wz=a.wz;
	}
}f[N*4];
ll a[N];
int n,h[N],tot;
ll m,ans;
void build(int l,int r,int s){
	if (l==r){
		f[s].mn=a[l];
		f[s].wz=l;
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s]=f[s+s];
	f[s].combine(f[s+s+1]);
}
void get(int l,int r,int s,int ll,int rr,node1&a){
	if(r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		if (ll==l)a=f[s];
		else
			a.combine(f[s]);
		return;
	}
	get(l,(l+r)/2,s+s,ll,rr,a);
	get((l+r)/2+1,r,s+s+1,ll,rr,a);
}
void ins(int s,ll v,ll y,int sum){
	tri[s].sum+=sum;
	while (y){
		bool sig=((v&y)>0);
		if (!tri[s].son[sig])tri[s].son[sig]=++tot;
		s=tri[s].son[sig];
		tri[s].sum+=sum;
		y/=2;
	}
}
void get(int s,ll v,ll lim,ll y){
	if (!y){
		if (v>lim)return;
		ans+=tri[s].sum;
		return;
	}
	if (!s||v/y/2>lim/y/2)return;
	if (v/y/2<lim/y/2){
		ans+=tri[s].sum;
		return;
	}
	get(tri[s].son[0],v,lim,y/2);
	get(tri[s].son[1],v^y,lim,y/2);
}
int combine(int x,int y,ll t){
	if (!x)return y;
	if (!y)return x;
	tri[x].sum+=tri[y].sum;
	if (!t)return x;
	tri[x].son[0]=combine(tri[x].son[0],tri[y].son[0],t/2);
	tri[x].son[1]=combine(tri[x].son[1],tri[y].son[1],t/2);
	return x;
}
int work(int l,int r){
	if (l>r)return 0;
	node1 d;
	get(1,n,1,l,r,d);
	if (l!=r){
		int sl=work(l,d.wz-1);
		int sr=work(d.wz+1,r);
		if (!sl){
			get(h[sr],a[d.wz-1],m/d.mn,(ll)1<<30);
			if ((a[d.wz]^a[d.wz-1])<=m/d.mn)ans++;
			h[d.wz]=h[sr];	
		}else
		if (!sr){
			get(h[sl],a[d.wz],m/d.mn,(ll)1<<30);
			if ((a[d.wz]^a[l-1])<=m/d.mn)ans++;
			h[d.wz]=h[sl];
		}else{
			if (d.wz-l>=r-d.wz){
				h[d.wz]=h[sl];
				for (int i=d.wz;i<=r;i++){
					get(h[d.wz],a[i],m/d.mn,(ll)1<<30);
					if ((a[i]^a[l-1])<=m/d.mn)ans++;
				}
				combine(h[sl],h[sr],(ll)1<<30);
			}else{	
				h[d.wz]=h[sr];
				for (int i=l-1;i<d.wz;i++){
					get(h[d.wz],a[i],m/d.mn,(ll)1<<30);
					if ((a[d.wz]^a[i])<=m/d.mn)ans++;
				}
				combine(h[sr],h[sl],(ll)1<<30);
			}
		}
	}
	if (!h[d.wz]){
		h[d.wz]=++tot;
		if ((a[d.wz]^a[d.wz-1])<=m/d.mn)ans++;
	}
	ins(h[d.wz],a[d.wz],(ll)1<<30,1);
	return d.wz;
}
int main(){
	freopen("k.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	for (int i=1;i<=n;i++)
		a[i]^=a[i-1];
	work(1,n);
	cout<<ans;
	return 0;
}
