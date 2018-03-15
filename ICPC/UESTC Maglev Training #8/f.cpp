#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N];
int n,T,tot;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		tot=0;
		for (int i=1;i<=n;i+=2)
			a[i]=++tot;
		for (int i=2;i<=n;i+=2)
			a[i]=++tot;
		printf("%d",a[1]);
		for (int i=2;i<=n;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
