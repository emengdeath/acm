#include<bits/stdc++.h>
using namespace std;
long long even(long long l,long long r){
	long long res = (r-l+1)/2;
	if ((r-l+1)%2==1&&l%2==0)res++;
	return res;
}
long long get(long long x,long long l,long long r){
	if (x%2==1)return (x+1)/2;
	return get(even(l,x)+r,r+1,r+even(l,r));
}
int main(){
	long long n=1e18;
	for (long long i=1;;i++){
		if (get(i,1,n)<=0){
			printf("%lld\n",i);
			return 0;
		}
	}
	return 0;
}
