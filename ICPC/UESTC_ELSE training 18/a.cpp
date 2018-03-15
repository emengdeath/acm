#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;
int n,T,ans;
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		int x=1;
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;i++){
			x=x*2%7;
			ans+=(x==1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
