#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
unsigned long long k,d,t;
int main(){
	scanf("%I64u %I64u %I64u",&k,&d,&t);
	unsigned long long ans=0;
	unsigned long long dd=k/d;
	if (dd*d==k)d=dd*d;else d=(dd+1)*d;
	t*=2;
	unsigned long long s=t/(d+k);
	t-=s*(d+k),ans+=d*2*s;
	if (t<=k*2)ans+=t;
	else
		t-=k*2,ans+=k*2,ans+=t*2;
	printf("%I64d",ans/2);
	if (ans&1)printf(".5");
	return 0;
}
