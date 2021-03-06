#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000
using namespace std;
int n,m;
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int main(){
	scanf("%d %d",&n,&m);
	if (gcd(n,m)!=1)printf("infinity infinity");
	else{
		if (n>m)swap(n,m);
		if (n==1){
			printf("0 -1");
		}else{
			long long s=(long long)(n-1)*m-n;
			printf("%I64d %I64d",s-s/2,s);
		}
	}
	return 0;
}
