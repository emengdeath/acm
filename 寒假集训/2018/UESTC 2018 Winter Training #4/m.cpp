#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long ans;
int m,k,T;
long long calc(int n){
	long long s=m/(k+1)*k;
	long long all=0;
	int x=m%(k+1);
	all+=x-1+s;
	if (x<=n){
		return all*x+(n-x)*(all+1);
	}else
		return all*=n;
}
int main(){
	freopen("chess.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		ans=0;
		scanf("%d %d",&m,&k);
		long long all=calc(k+1);
		ans+=m/(k+1)*all;
		ans+=calc(m%(k+1));
		printf("%lld\n",ans);
	}
	return 0;
}
