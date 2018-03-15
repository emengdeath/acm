#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		int n;
		scanf("%d",&n);
		printf("%I64d\n",(long long)(n+1)*n/2-1);
	}
	return 0;
}
