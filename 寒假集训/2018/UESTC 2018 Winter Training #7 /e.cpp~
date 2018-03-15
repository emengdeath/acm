#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
int a[N];
int n,T;
bool check(){
	for (int i=2;i<=n;i++)
		if (a[i]!=a[i-1])return 0;
	return 1;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		while (!check()){
			sort(a+1,a+n+1);
			int x=a[n]-a[1];
			a[n]=a[1]=x;
		}
		printf("%d\n",a[1]);
	}
	return 0;
}
