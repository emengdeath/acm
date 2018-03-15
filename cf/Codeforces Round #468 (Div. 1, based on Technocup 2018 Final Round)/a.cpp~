#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int to[N],deep[N];
bool sum[N];
int n;
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++)scanf("%d",&to[i]);
	sum[0]=1;
	for (int i=2;i<=n;i++)sum[deep[i]=deep[to[i]]+1]^=1;
	int ans=0;
	for (int i=0;i<=n;i++)ans+=sum[i];
	printf("%d\n",ans);
	return 0;
}
