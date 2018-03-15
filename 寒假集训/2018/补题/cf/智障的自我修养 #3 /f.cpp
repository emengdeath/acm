#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int sum[N*3];
int k;
long long n;
int main(){
	scanf("%I64d %d",&n,&k);
	int maxn=0;
	for (int i=0;n;i++){
		k-=(n&1);
		sum[i+N]=(n&1);
		n/=2;
		if (sum[i+N])maxn=i;
	}
	if (k<0){
		printf("No");
		return 0;
	}
	while (k){
		while (sum[maxn+N]&&k)sum[maxn-1+N]+=2,sum[maxn+N]--,k--;
		maxn--;
	}
	if (sum[maxn+1+N]){
		while (sum[maxn+N]>=2)sum[maxn+N]-=2,sum[maxn+N+1]++,k++;
		for (int i=-N;;i++)
			if (sum[i+N]){
				while (k)sum[i+N]--,sum[i-1+N]+=2,k--,i--;
				break;
			}
	}
	printf("Yes\n");
	for (int i=N;i>=-N;i--)
		while (sum[i+N])printf("%d ",i),sum[i+N]--;
	return 0;
}
