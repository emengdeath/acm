#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
long long a[N];
int ans[N];
long long p;
int k;
int main(){
	scanf("%I64d %d",&p,&k);
	bool sig=1;
	while (p){
		if (sig)	
			ans[++ans[0]]=p%k,p/=k;
		else{
			if (p%k)ans[++ans[0]]=k-p%k,(p/=k)+=1;
			else
				ans[++ans[0]]=0,p/=k;
		}
		sig^=1;
	}
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	return 0;
}
