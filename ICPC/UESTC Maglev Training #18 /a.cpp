#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int maxn;
int n;
struct node{
	int h,r,t;
	bool check(int x){
		x=x%h;
		if (r<=t)
			return x<=r||t<=x;
		else
			return x<=r&&x>=t;
	}
}a[100];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].h,&a[i].r,&a[i].t);
		maxn=max(a[i].h,maxn);
	}
	for (int i=0;i<maxn*1825;i++){
		bool bz=1;
		for (int j=1;j<=n;j++)
			bz&=a[j].check(i);
		if (bz){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("impossible\n");
	return 0;
}
