#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long ans,x;
int n;
int a[10000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	x=1;
	ans=1;
	for (int i=n;i;i--)
		x*=a[i],ans+=x;
	printf("%llu\n",ans);
	return 0;
}
