#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
#define MOD 1000000007
using namespace std;
int g[N],a[N][2],l[N],r[N];
int help[6]={2,3,5,7,11,13};
struct node{
	int x[6];
	long long calc(long long x,long long y){
		long long s=1;
		while (y){
			if (y&1)(s*=x)%=MOD;
			(x*=x)%=MOD,y/=2;
		}
		return s;
	}
	int get1(){
		long long s=1;
		for (int i=0;i<6;i++)
			(s*=calc(help[i],x[i]))%=MOD;
		return s;
	}
	int get2(){
		long long s=1;
		for (int i=0;i<6;i++)
			(s*=x[i]+1)%=MOD;
		return s;
	}
}f[N*4],v[N],e,d;
int n,q;
node operator+(node a, node b){
	for (int i=0;i<6;i++)
		a.x[i]+=b.x[i];
	return a;
}
void ins(int x,int y){
	static int sum=1;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x){
	static int calc=0;
	l[x]=++calc;
	for (int i=g[x];i;i=a[i][1])
		dfs(a[i][0]);
	r[x]=calc;
}
node get(int x){
	node s=e;
	for (int i=0;i<6;i++){
		while (!(x%help[i]))x/=help[i],s.x[i]++;
	}
	return s;
}
void ins(int l,int r,int s,int ll,node v){
	f[s]=f[s]+v;
	if (l==r)return;
	if ((l+r)/2>=ll)ins(l,(l+r)/2,s+s,ll,v);
	else
		ins((l+r)/2+1,r,s+s+1,ll,v);
}
void get(int l,int r,int s,int ll,int rr){
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		d=d+f[s];
		return;
	}
	get(l,(l+r)/2,s+s,ll,rr);
	get((l+r)/2+1,r,s+s+1,ll,rr);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ins(x,y);
	}
	dfs(0);
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		ins(1,n,1,l[i],get(x));
	}
	scanf("%d",&q);
	while (q--){
		char s[10];
		int x,y;
		scanf(" %s %d",s,&x);
		if (s[0]=='R'){
			d=e;
			get(1,n,1,l[x],r[x]);
			printf("%d %d\n",d.get1(),d.get2());
		}else{
			scanf("%d",&y);
			ins(1,n,1,l[x],get(y));
		}
	}
	return 0;
}
