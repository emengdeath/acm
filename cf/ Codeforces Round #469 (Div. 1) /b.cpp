#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long n,x;
int q;
int main(){
	scanf("%I64u %d",&n,&q);
	while (q--){
		scanf("%I64u",&x);
		while (!(x&1)){
			x=x/2+n;
		}
		printf("%I64u\n",(x+1)/2);
	}
	return 0;
}
