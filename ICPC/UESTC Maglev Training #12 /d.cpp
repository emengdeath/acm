#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100000
using namespace std;
int a[N];
long long b[N],c[N];
double ans;
int n,m,mid;
long double sqr(long double b){
	return b*b;
}
double get(int l,int r){
	long double s=(long double)(b[r]-b[l-1])/(r-l+1);
	return s*s*(r-l+1)+c[r]-c[l-1]-2*(b[r]-b[l-1])*s;
}
int main(){
	freopen("d.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (n==m){
			printf("0\n");
			continue;
		}
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++)
			b[i]=b[i-1]+a[i],c[i]=c[i-1]+sqr(a[i]);
		mid=0;
		ans=get(1,n-m);
		for (int i=2;i<=m+1;i++)
			ans=min(ans,get(i,i+(n-m)-1));
		printf("%.11f\n",ans);
	}
	return 0;
}
