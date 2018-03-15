#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 3000000
using namespace std;
struct node{
	int x,bz;
}f[N],g[N];
int a[N],b[N];
int n;
void down(node*f,int l,int r,int s){
	if (f[s].bz){
		f[s].x+=f[s].bz;
		if (l!=r)f[s+s].bz+=f[s].bz,f[s+s+1].bz+=f[s].bz;
		f[s].bz=0;
	}
}
void ins(node*f,int l,int r,int s,int ll,int rr){
	down(f,l,r,s);
	if (rr<b[l]||b[r]<ll)return;
	if (ll<=b[l]&&b[r]<=rr){
		f[s].bz=1;
		down(f,l,r,s);
		return;
	}
	ins(f,l,(l+r)/2,s+s,ll,rr),ins(f,(l+r)/2+1,r,s+s+1,ll,rr);
	f[s].x=min(f[s+s].x,f[s+s+1].x);
}
int get(node*f,int l,int r,int s,int ll,int rr){
	down(f,l,r,s);
	if (b[r]<ll||rr<b[l])return 1e9;
	if (ll<=b[l]&&b[r]<=rr)return f[s].x;
	return min(get(f,l,(l+r)/2,s+s,ll,rr),get(f,(l+r)/2+1,r,s+s+1,ll,rr));
}
void ins1(node*f,int l,int r,int s,int ll,int v){
	down(f,l,r,s);
	if (b[r]<ll||b[l]>ll)return;
	if (l==r){
		f[s].x=v;
		return;
	}
	ins1(f,l,(l+r)/2,s+s,ll,v),ins1(f,(l+r)/2+1,r,s+s+1,ll,v);
	f[s].x=min(f[s+s].x,f[s+s+1].x);
}
void ins2(node*f,int l,int r,int s,int ll,int v){
	down(f,l,r,s);
	if (b[r]<ll||b[l]>ll)return;
	if (l==r){
		f[s].x=min(v,f[s].x);
		return;
	}
	ins2(f,l,(l+r)/2,s+s,ll,v),ins2(f,(l+r)/2+1,r,s+s+1,ll,v);
	f[s].x=min(f[s+s].x,f[s+s+1].x);
}
int main(){
	//freopen("g.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[++b[0]]=(a[i]-=i),b[++b[0]]=a[i]-1,b[++b[0]]=a[i]+1;
	sort(b+1,b+b[0]+1);
	int ss=b[0];
	b[0]=1;
	for (int i=1;i<=ss;i++)if (b[i]!=b[b[0]])b[++b[0]]=b[i];
	int ans;
	int last=0;
	for (int i=1;i<=n;i++){
		ins1(g,1,b[0],1,a[i],min(last,get(g,1,b[0],1,b[1],a[i])));
		ins(g,1,b[0],1,a[i]+1,b[b[0]]);
		ins(g,1,b[0],1,b[1],a[i]-1);
		last=get(f,1,b[0],1,b[1],a[i+1]+1);		
		ins1(f,1,b[0],1,a[i],get(f,1,b[0],1,b[1],a[i]));
		ins(f,1,b[0],1,a[i]+1,b[b[0]]);
		ins(f,1,b[0],1,b[1],a[i]-1);
if (i==n-1)ans=f[1].x;
		
	}
	down(f,1,b[0],1);
	down(g,1,b[0],1);
	printf("%d\n",min(g[1].x,ans));
	return 0;
}
