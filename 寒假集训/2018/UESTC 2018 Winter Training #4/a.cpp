#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,T;
int main(){
	freopen("tabs.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&k);
		if (n==1)printf("0\n");
		else
			n==k||k==1?printf("1\n"):printf("2\n");
	}
	return 0;
}
