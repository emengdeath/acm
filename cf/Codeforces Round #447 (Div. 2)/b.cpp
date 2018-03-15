#include<iostream>
#include<algorithm>
#include<cstdio>
#define MOD 1000000007
using namespace std;
int ans,k;
long long n,m;
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
	scanf("%I64d %I64d %d",&n,&m,&k);
	//printf("%I64d\n",calc(2,(n-1)%(MOD-1)*((m-1)%(MOD-1))%(MOD-1)));
	if (((n+m)&1)&&k==-1)printf("0");
	else
		printf("%I64d\n",calc(calc(2,n-1),m-1));
	return 0;
}
