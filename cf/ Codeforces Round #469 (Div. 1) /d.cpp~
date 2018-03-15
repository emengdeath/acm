#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
using namespace std;
struct node{
	long long sig,v;
	bool bz;
}f[N*4];
int a[N];
int n,d,b;
long long v;
bool bz;
void down(int l,int r,int s){
	if (f[s].sig){
		f[s].v-=f[s].sig;
		if (l!=r){
			if (f[s].bz){
				if (f[s+s].v>=f[s].sig+f[s+s].sig){
					f[s+s].sig+=f[s].sig;
					f[s+s].bz=f[s].bz;
				}else{
					f[s].sig-=(f[s+s].v-f[s+s].sig);
					f[s+s].sig=f[s+s].v;
					f[s+s+1].sig+=f[s].sig;
					f[s+s].bz=f[s+s+1].bz=f[s].bz;
				}
			}else{
				if (f[s+s+1].v>=f[s].sig+f[s+s+1].sig){
					f[s+s+1].sig+=f[s].sig;
					f[s+s+1].bz=f[s].bz;
				}else{
					f[s].sig-=f[s+s+1].v-f[s+s+1].sig;
					f[s+s+1].sig=f[s+s+1].v;
					f[s+s].sig+=f[s].sig;
					f[s+s].bz=f[s+s+1].bz=f[s].bz;
				}
			}
		}
		f[s].sig=0;
	}
}
void build(int l,int r,int s){
	f[s].sig=0;
	if (l==r){
		f[s].v=a[l];
		return;
	}
	build(l,(l+r)/2,s+s);
	build((l+r)/2+1,r,s+s+1);
	f[s].v=f[s+s].v+f[s+s+1].v;
}
void build1(int l,int r,int s){
	down(l,r,s);
	if (l==r)return;
	build1(l,(l+r)/2,s+s),build1((l+r)/2+1,r,s+s+1);
}
long long get(int l,int r,int s,int ll,int rr){
	down(l,r,s);
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s].v;
	return get(l,(l+r)/2,s+s,ll,rr)+get((l+r)/2+1,r,s+s+1,ll,rr);
}
void change(int l,int r,int s,int ll,int rr){
	down(l,r,s);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		f[s].sig=min(v,f[s].v);
		v-=f[s].sig;
		f[s].bz=bz;
		down(l,r,s);
		return;
	}
	if (bz){
		change(l,(l+r)/2,s+s,ll,rr);
		change((l+r)/2+1,r,s+s+1,ll,rr);
	}else{
		change((l+r)/2+1,r,s+s+1,ll,rr);
		change(l,(l+r)/2,s+s,ll,rr);
	}
	f[s].v=f[s+s].v+f[s+s+1].v;
}
bool check(int s){
	build(1,n,1);
	int ans=n/2+(n&1);
	if (ans>s){
		for (int i=1;i<=n/2+(n&1);i++)
			if (get(1,n,1,i-d*i,i+d*i)>=b){
				ans--;
				bz=1,v=b;
				change(1,n,1,i-d*i,i+d*i);
				if (ans==s)break;
			}
		if (ans>s)return 0;
	}
	build1(1,n,1);
	ans=n/2;
	if (ans>s){
		for (int i=n;i>n/2+(n&1);i--)
			if (get(1,n,1,i-d*(n-i+1),i+d*(n-i+1))>=b){
				ans--;
				bz=0,v=b;
				change(1,n,1,i-d*(n-i+1),i+d*(n-i+1));
				if (ans==s)break;
			}
		if (ans>s)return 0;
	}
	return 1;
}
int main(){
	//freopen("d.in","r",stdin);
	scanf("%d %d %d",&n,&d,&b);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=n,s=n,mid;
	while (l<=r){
		if (check(mid=(l+r)/2))s=min(s,mid),r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",s);
	return 0;
}
