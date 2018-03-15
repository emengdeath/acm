#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 30000001
#define MOD 30000000
using namespace std;
int a[N],f[N];
int n,m,q;
int main(){
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]),f[a[i]]++;
	for (int i=m+1;i<=n;i++)
		a[i]=(a[i-m]+a[i-m+1])%MOD,f[a[i]]++;
	int l=0;
	for (int i=1;i<=n;i++){
		while (!f[l])l++;
		a[i]=l;
		f[l]--;
	}
	while (q--){
		int x;
		scanf("%d",&x);
		printf("%d\n",a[x]);
	}
	return 0;
}
