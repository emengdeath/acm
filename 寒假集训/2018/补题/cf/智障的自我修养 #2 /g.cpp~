#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
int n,k;
int sum[N];
bool bz[N];
long long all;
int main(){
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		bz[i]=1;
		for (int j=2;(long long)j*i<=n;j++)
			sum[j*i]++,all++;
	}
	if (all<k){
		printf("No");
		return 0;
	}
	for (int i=n;i;i--){
		int tot=sum[i];
		for (int j=2;(long long)j*i<=n;j++)
			if (bz[i*j])tot++;
		if (tot>1&&all-tot>=k){
			bz[i]=0,all-=tot;
			for (int j=1;(long long)j*i<=n;j++)
				if (bz[i*j])sum[i*j]--;
		}
	}
	for (int i=n;i;i--)
	if (bz[i]){
		int tot=sum[i];
		for (int j=2;(long long)j*i<=n;j++)
			if (bz[i*j])tot++;
		if (tot==1&&all-tot>=k){
			bz[i]=0,all-=tot;
			for (int j=1;(long long)j*i<=n;j++)
				if (bz[i*j])sum[i*j]--;
		}
	}
	if (all==k){
		printf("Yes\n");
		int tot=0;
		for (int i=1;i<=n;i++)tot+=bz[i];
		printf("%d\n",tot);
		for (int i=1;i<=n;i++)if (bz[i])printf("%d ",i);
	}else
		printf("No");
	return 0;
}
