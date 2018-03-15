#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	long long n,m;
	scanf("%I64d %I64d",&n,&m);
	while (1){
		if (!n||!m)break;
		else
		if (n>=2*m)n%=(2*m);
		else
		if (m>=2*n)m%=(2*n);
		else
			break;
	}
	printf("%I64d %I64d",n,m);
	return 0;
}
