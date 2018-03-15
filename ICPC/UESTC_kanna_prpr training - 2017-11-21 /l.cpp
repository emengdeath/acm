#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000
using namespace std;
long long n;
long long ans[N][N];
int tot;
bool bz[N];
long long cheng(long long s,long long y){
	long long x=0;
	while (y){
		if (s>n)return n+1;
		if (y&1){
			x+=s;
			if (x>n)return n+1;
		}
		s+=s;
		y/=2;
	}
	return x;
}
long long power(int x,long long y){
	long long s=1;
	while (x--){
		s=cheng(s,y);
		if (s>n)return n+1;
	}
	return s;
}
long long er(int x){
	long long l=1,r=n,mid,s=l;
	while (l<=r){
		if (power(x,mid=(l+r)/2)<=n)l=mid+1,s=max(mid,s);
		else
			r=mid-1;
	}
	return s;
}
long long update(long long x){
	long long nn;
	++tot;
	nn=n;
	ans[tot][0]=0;
	while (!(nn%x)){
		nn/=x;
		ans[tot][++ans[tot][0]]=x;
	}
	while (!(nn%(x+1))){
		nn/=(x+1);
		ans[tot][++ans[tot][0]]=x+1;
	}
	if (bz[ans[tot][0]])tot--;
	else
		bz[ans[tot][0]]=1;
}
int main(){
//	freopen("little.in","r",stdin);
//	freopen("little.out","w",stdout);
	scanf("%lld",&n);
	long long nn=n;
	while (nn%2==0)nn/=2;
	if (nn==1){
		printf("-1");
		return 0;
	}
	for (int i=1;i<=64;i++){
		long long x=er(i);
		if (x==1)continue;
		long long nn=n;
		while (!(nn%x))nn/=x;
		while (!(nn%(x+1)))nn/=(x+1);
		if (nn==1)
			update(x);
	}	
	for (int x=2;x<=1000000;x++){
		long long nn=n;
		while (!(nn%x))nn/=x;
		while (!(nn%(x+1)))nn/=(x+1);
		if (nn==1)
			update(x);
	}
	if (!tot)printf("-1");
	else{
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++){
			printf("%lld",ans[i][0]);
			for (int j=1;j<=ans[i][0];j++)
				printf(" %lld",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
