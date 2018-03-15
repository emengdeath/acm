#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N],sum[N];
int n;
long long ans;
int main(){
	scanf("%d",&n);
	long long r=0;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),r+=a[i];
	sort(a+1,a+n+1);
	ans=r;
	long long l=0;
	for (int i=1;i<=n;i++){
		r-=a[i];
		l+=a[i];
		ans=min(ans,r-(long long)a[i]*(n-i)+(long long)i*a[i]-l);
	}
	printf("%I64d\n",ans);
	return 0;
}
