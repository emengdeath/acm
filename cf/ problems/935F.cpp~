#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
struct node{
	long long all,x,up;
}f[N];
int a[N];
int n;
void build(int l,int r,int s){
	if (l==r){
		f[s].x=a[l];
		if (l==1)return;
		f[s].all=abs(a[l]-a[l-1]);
		if (l-1&&l+1<=n){
			if ((a[l]>=a[l-1]&&a[l]>=a[l+1]))f[s].up=0;
			else
			if (a[l]<=a[l-1]&&a[l]<=a[l+1])f[s].up=(min(a[l-1],a[l+1])-a[l])*2+max(a[l-1],a[l+1])-min(a[l-1],a[l+1]);
			else
			f[s].up=max(a[l-1],a[l+1])-a[l];
		}
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s].all=f[s+s].all+f[s+s+1].all;
	f[s].up=min(f[s+s].up,f[s+s+1].up);
}
long long get2(int l,int r,int s,int ll,int rr){
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s].all;
	return get2(l,(l+r)/2,s+s,ll,rr)+get2((l+r)/2+1,r,s+s+1,ll,rr);
}
long long get1(int l,int r,int s,int ll,int rr){
	if (r<ll||rr<l)return (long long)1e9*1e9;
	if (ll<=l&&r<=rr)return f[s].up;
	return min(get1(l,(l+r)/2,s+s,ll,rr),get1((l+r)/2+1,r,s+s+1,ll,rr));
}
void down(int l,int r,int s){
	if (l!=r&&f[s].x){
		f[s+s].x+=f[s].x;
		f[s+s+1].x+=f[s].x;
		f[s].x=0;
	}
}
long long get(int l,int r,int s,int ll){
	down(l,r,s);
	if (l==r)return f[s].x;
	if ((l+r)/2>=ll)return get(l,(l+r)/2,s+s,ll);
	else
		return get((l+r)/2+1,r,s+s+1,ll);
}
void change(int l,int r,int s,int ll,long long up,long long v){
	if (l==r){
		f[s].all=v;
		f[s].up=up;
		return;
	}
	if ((l+r)/2>=ll)change(l,(l+r)/2,s+s,ll,up,v);
	else
		change((l+r)/2+1,r,s+s+1,ll,up,v);
	f[s].all=f[s+s].all+f[s+s+1].all;
	f[s].up=min(f[s+s].up,f[s+s+1].up);
}
void ins(int l,int r,int s,int ll,int rr,int v){
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		f[s].x+=v;
		return;
	}
	ins(l,(l+r)/2,s+s,ll,rr,v);
	ins((l+r)/2+1,r,s+s+1,ll,rr,v);
}
void work(int l,int r,int v,int ll){
	if (ll>n||ll<=1)return;
	long long s=0;
	long long x=get(1,n,1,ll-1),y=get(1,n,1,ll);
	if (l<=ll-1&&ll-1<=r)x+=v;
	if (l<=ll&&ll<=r)y+=v;
	if (ll!=n){
		long long z=get(1,n,1,ll+1);
		if (l<=ll+1&&ll+1<=r)z+=v;;
		if (y>=x&&y>=z)s=0;
		else
		if (y<=x&&y<=z)s=(min(x,z)-y)*2+max(x,z)-min(x,z);
		else
			s=max(x,z)-y;
	}
	change(1,n,1,ll,s,abs(y-x));
}
long long change(int ll,int v){
	long long s=get2(1,n,1,1,ll-1)+get2(1,n,1,ll+2,n);
	long long x=get(1,n,1,ll)+v;
	if (ll!=1){
		s+=abs(get(1,n,1,ll-1)-x);
	}
	if (ll!=n)
		s+=abs(get(1,n,1,ll+1)-x);
	return s;
}
int main(){
//	freopen("935F.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	int m;
	scanf("%d",&m);
	while (m--){
		int sig,l,r,v;
		scanf("%d %d %d %d",&sig,&l,&r,&v);
		if (sig==1){
			printf("%I64d\n",max(change(l,v),max(change(r,v),((v-get1(1,n,1,max(l,2),min(r,n-1))))*2+f[1].all)));
		}else{
			work(l,r,v,l);
			work(l,r,v,l+1);
			work(l,r,v,l-1);
			work(l,r,v,r);
			work(l,r,v,r+1);
			work(l,r,v,r-1);
			ins(1,n,1,l,r,v);
		}
	}
	return 0;
}
