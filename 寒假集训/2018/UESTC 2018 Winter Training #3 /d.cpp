#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100];
int n;
int main(){
	scanf("%d",&n);
	while (n){
		if (n&1)a[++a[0]]=0,n/=2;
		else
			a[++a[0]]=1,n=(n-2)/2;
	}
	for (int i=a[0];i;i--)
		a[i]?printf("B"):printf("A");
	return 0;
}
