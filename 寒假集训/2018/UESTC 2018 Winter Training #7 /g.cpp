#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N];
int n;
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int main(){
	int sig=0;
	while (scanf("%d",&n)!=EOF){
		printf("Case %d: ",++sig);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)a[1]=gcd(a[1],a[i]);
		if (a[1]==1){
			printf("%d\n",(n-1)*2);
			for (int i=1;i<=2;i++)
				for (int j=2;j<=n;j++)
					printf("1 %d\n",j);
		}else printf("-1\n");
		printf("\n");
	}
	return 0;
}
