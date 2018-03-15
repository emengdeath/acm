#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 3000000
using namespace std;
int n,m,tot;
int f[N*4],q[N][3],l[N],r[N],a[N];
void build(int L,int R,int s){
	f[s]=r[R]-l[L]+1;
	if (L==R)return;
	build(L,(L+R)/2,s+s),build((L+R)/2+1,R,s+s+1);
}
void down(int L,int R,int s){
	if (f[s]<0){
		if (L!=R)f[s+s]=f[s],f[s+s+1]=f[s];
		if (f[s]==-2)f[s]=0;
		else
			f[s]=r[R]-l[L]+1;
	}
}
void change(int L,int R,int s,int ll,int rr,int sig){
	down(L,R,s);
	if (r[R]<ll||rr<l[L])return;
	if (ll<=l[L]&&r[R]<=rr){
		f[s]=sig-3;
		down(L,R,s);
		return;
	}
	change(L,(L+R)/2,s+s,ll,rr,sig);
	change((L+R)/2+1,R,s+s+1,ll,rr,sig);
	f[s]=f[s+s]+f[s+s+1];
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)scanf("%d %d %d",&q[i][0],&q[i][1],&q[i][2]),a[i]=q[i][0],a[i+m]=q[i][1];
	sort(a+1,a+m+m+1);
	for (int i=1;i<=m+m;i++)
		if (a[i]!=a[i-1]){
			if (a[i]-a[i-1]>1)l[++tot]=a[i-1]+1,r[tot]=a[i]-1;
			l[++tot]=a[i],r[tot]=a[i];
		}
	if (a[m+m]!=n)l[++tot]=a[m+m]+1,r[tot]=n;
	build(1,tot,1);
	for (int i=1;i<=m;i++){
		change(1,tot,1,q[i][0],q[i][1],q[i][2]);
		printf("%d\n",f[1]);
	}
	return 0;
}

