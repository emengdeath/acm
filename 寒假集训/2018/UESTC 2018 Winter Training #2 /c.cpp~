#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100001
#include<cstring>
#define MOD 1000000007
using namespace std;
long long f[N*4],sig1[N*4],sig2[N*4],ans;
int n,m;
int a[N];
long long calc(long long x,long long y){
	long long s=1;
	x%=MOD,y%=MOD-1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
		if (x==1)break;
	}
	return s;
}
void down(int l,int r,int s){
	if (l!=r){
		if (sig2[s]!=1){
			f[s]=calc(f[s],sig2[s]);
			sig1[s+s]=calc(sig1[s+s],sig2[s]);
			sig1[s+s+1]=calc(sig1[s+s+1],sig2[s]);
			(sig2[s+s]*=sig2[s])%=(MOD-1);
			(sig2[s+s+1]*=sig2[s])%=(MOD-1);
			sig2[s]=1;
		}
		if (sig1[s]!=1){
			(f[s]*=calc(sig1[s],r-l+1))%=MOD;
			(sig1[s+s]*=sig1[s])%=MOD;
			(sig1[s+s+1]*=sig1[s])%=MOD;
			sig1[s]=1;
		}
	}else{
		if (sig2[s]!=1){
			f[s]=calc(f[s],sig2[s]);
			sig2[s]=1;
		}
		if (sig1[s]!=1){
			(f[s]*=calc(sig1[s],r-l+1))%=MOD;
			sig1[s]=1;
		}
	}
}
void build(int l,int r,int s){
	sig1[s]=sig2[s]=1;
	if (l==r){
		f[s]=a[l];
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s]=f[s+s]*f[s+s+1]%MOD;
}
void change(int l,int r,int s,int ll,int rr,int sig,int v){
	down(l,r,s);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		if (sig==1)sig1[s]=v;
		else
			sig2[s]=v;
		down(l,r,s);
		return;
	}
	change(l,(l+r)/2,s+s,ll,rr,sig,v),change((l+r)/2+1,r,s+s+1,ll,rr,sig,v);
	f[s]=f[s+s]*f[s+s+1]%MOD;
}
void get(int l,int r,int s,int ll,int rr){
	down(l,r,s);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		(ans*=f[s])%=MOD;
		return;
	}
	get(l,(l+r)/2,s+s,ll,rr),get((l+r)/2+1,r,s+s+1,ll,rr);
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		build(1,n,1);
		while (m--){
			int sig,l,r,x;
			scanf("%d %d %d",&sig,&l,&r);
			if (sig<=2){
				scanf("%d",&x);
				change(1,n,1,l,r,sig,x);
			}else{
				ans=1;
				get(1,n,1,l,r);
				printf("%d\n",(int)ans);
			}
		}
	}
	return 0;
}
