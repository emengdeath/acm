#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
int T,n;
int a[N],f[N];
int main(){
	freopen("overcode.in","r",stdin);
	scanf("%d ",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=6;i<=n;i++){
			f[i]=f[i-1];
			if (a[i]-a[i-5]<=1000)
				f[i]=max(f[i],f[i-6]+1);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
