#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int n;
long long all,ans;
int a[N];
long long b[N];
void work(long long x){
	long long y=0,s=0,t;
	b[0]=0;
	for (int i=1;i<=n;i++){
		y+=x-a[i]%x;
		b[++b[0]]=(x-a[i]%x);
	}
	t=y/x;
	sort(b+1,b+b[0]+1);
	for (int i=1;i<=b[0]-t;i++)
		s+=b[i];
	ans=min(ans,s);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		all=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),all+=a[i];
		ans=all;
		int x=2;
		long long y=all;
		while ((long long)x*x<=all){
			if (!(all%x)){
				work(x);
				while (!(all%x))all/=x;
			}
			x++;
		}
		if (all!=1)work(all);
		printf("%I64d\n",ans);
	}
	return 0;
}
