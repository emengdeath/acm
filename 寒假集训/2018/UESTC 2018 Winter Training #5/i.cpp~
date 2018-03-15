#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
struct node{
	long long all;
	int min,max;
}f[N],d;
int a[N][2];
int n,L,m;
bool sig;
node operator+(node a,node b){
	a.all+=b.all;
	a.min=min(b.min,a.min);
	a.max=max(b.max,a.max);
	return a;
}
void build(int l,int r,int s){
	if (l==r){
		f[s].min=f[s].max=f[s].all=a[l][1];
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s]=f[s+s]+f[s+s+1];
}
void get(int l,int r,int s,int ll,int rr){
	if (a[r][0]<ll||a[l][0]>rr)return;
	if (ll<=a[l][0]&&a[r][0]<=rr){
		if (!sig)L=l,sig=1,d=f[s];
		else
			d=d+f[s],L=min(L,l);
		return;	
	}
	get(l,(l+r)/2,s+s,ll,rr),get((l+r)/2+1,r,s+s+1,ll,rr);
}
int main(){
	while (scanf("%d",&n)!=EOF){
		int ans=0;
		for (int i=1;i<=n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		build(1,n,1);
		scanf("%d",&m);
		while (m--){
			char x[10],y[10];
			int z;
			scanf(" %s %s %d",x,y,&z);
			ans=0;
			for (int i=2;i<=n;i++){
				sig=0;
				get(1,n,1,a[i][0]-z,a[i][0]-1);
				L=i-L;
				if (sig){
				if (x[0]=='g'){
					if (y[0]=='a')
						ans+=((long long)a[i][1]*L>d.all);
					else
					if (y[1]=='i')
						ans+=(a[i][1]>d.min);
					else
						ans+=(a[i][1]>d.max);
				}else{
					if (y[0]=='a')
						ans+=((long long)a[i][1]*L<d.all);
					else
					if (y[1]=='i')
						ans+=(a[i][1]<d.min);
					else
						ans+=(a[i][1]<d.max);
				}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
