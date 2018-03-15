#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000001
using namespace std;
long long a[N];
int n;
long long ans1,ans2;
struct node{
	int to[10];
}f[N*15];
int calc;
void ins(int x,long long v,long long y){
	while (y){
		if (!f[x].to[v/y%10])f[x].to[v/y%10]=++calc;
		x=f[x].to[v/y%10];
		y/=10;
	}
}
void getmn(int x,long long v,long long y){
	long long s=0;
	while (y){
		int z=(10-v/y%10)%10;
		for (int i=1;i<=10;i++,z=(z+1)%10)
			if (f[x].to[z]){
				s+=(z+v/y%10)%10*y;
				x=f[x].to[z];
				break;
			}
		y/=10;
	}
	if (ans1==-1||ans1>s)ans1=s;
}
void getmx(int x,long long v,long long y){
	long long s=0;
	while (y){
		int z=9-v/y%10;
		for (int i=1;i<=10;i++,z=(z+9)%10)
			if (f[x].to[z]){
				s+=(z+v/y%10)%10*y;
				x=f[x].to[z];
				break;
			}
		y/=10;
	}
	ans2=max(ans2,s);
}
int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	ans1=-1;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if (i!=1){
			getmn(0,a[i],(long long)1e18);
			getmx(0,a[i],(long long)1e18);
		}
		ins(0,a[i],(long long)1e18);
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
