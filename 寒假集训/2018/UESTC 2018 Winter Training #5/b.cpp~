#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
bool a[1<<11];
int n;
int main(){
	while (scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		int ans=0;
		while (n--){
			long long x,v=0;
			scanf("%lld",&x);
			while (x){
				v|=(1<<(x%10));
				x/=10;
			}
			if (!a[v])a[v]=1,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
