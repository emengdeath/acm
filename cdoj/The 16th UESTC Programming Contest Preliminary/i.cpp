#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
const ui N=4e5+233;
struct node{
	ui k,b,x,v,ans;
}f[N]; 
ui a[N];
ui n,q;
void build(ui l,ui r,ui s){
	if (l==r){
		f[s].v=a[l];
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s].v=f[s+s].v+f[s+s+1].v;
}
void down(ui l,ui r,ui s,ui tag){
	if (f[s].k||f[s].b){
		f[s].ans+=f[s].k*f[s].v+f[s].b*(r-l+1);
		if (l!=r){
			f[s+s].k+=f[s].k,f[s+s+1].k+=f[s].k;
			f[s+s].b+=f[s].b+f[s].k*f[s+s].x,f[s+s+1].b+=f[s].b+f[s].k*f[s+s+1].x;
		}
		f[s].k=f[s].b=0;
	}
}
void adda(ui l,ui r,ui s,ui ll,ui rr,ui v,ui tag){
	tag+=f[s].x;
	down(l,r,s,tag);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		f[s].x+=v;
		return;
	}
	adda(l,(l+r)/2,s+s,ll,rr,v,tag),adda((l+r)/2+1,r,s+s+1,ll,rr,v,tag);
	ui mid=(l+r)/2;
	f[s].v=f[s+s].v+f[s+s+1].v+f[s+s].x*(mid-l+1)+f[s+s+1].x*(r-mid);
}
void addb(ui l,ui r,ui s,ui ll,ui rr,ui k,ui b,ui tag){
	tag+=f[s].x;
	down(l,r,s,tag);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		f[s].k+=k;
		f[s].b+=b+k*tag;
		down(l,r,s,tag);
		return;
	}
	addb(l,(l+r)/2,s+s,ll,rr,k,b,tag),addb((l+r)/2+1,r,s+s+1,ll,rr,k,b,tag);
	f[s].ans=f[s+s].ans+f[s+s+1].ans;
}
ui get(ui l,ui r,ui s,ui ll,ui rr,ui tag){
	tag+=f[s].x;
	down(l,r,s,tag);
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s].ans;
	return get(l,(l+r)/2,s+s,ll,rr,tag)+get((l+r)/2+1,r,s+s+1,ll,rr,tag);
}
int main(){
	//freopen("i.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for (ui i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	while (q--){
		ui sig,l,r;
		cin>>sig>>l>>r;
		if (sig==1){
			ui x;
			cin>>x;
			adda(1,n,1,l,r,x,0);
		}else
		if (sig==2){
			ui k,b;
			cin>>k>>b;
			addb(1,n,1,l,r,k,b,0);
		}else
			cout<<get(1,n,1,l,r,0)<<endl;
	}
	return 0;
}
