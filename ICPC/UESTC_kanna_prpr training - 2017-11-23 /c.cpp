#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a,b;
int T;
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		scanf("%I64d %I64d",&a,&b);
		if (a>b)swap(a,b);
		if (a==b)printf("1\n");
		else
			printf("2\n");
		printf("%I64d %I64d\n",a,b);
		if (a!=b)printf("%I64d %I64d\n",b,a);
	}
	return 0;
}
