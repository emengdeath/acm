#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
struct node{
	int x,y,z;
}a[N];
int n;
bool cmp(const node&a,const node&b){
	return a.x<b.x||(a.x==b.x&&(a.y<b.y||(a.y==b.y&&a.z<b.z)));
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
int gcd1(int x,int y){
	if (!x)return y;
	if (!y)return x;
	return gcd(x,y);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
	for (int i=2;i<=n;i++){
		a[i].x-=a[1].x;
		a[i].y-=a[1].y;
		a[i].z-=a[1].z;
		int v=gcd1(gcd1(abs(a[i].x),abs(a[i].y)),abs(a[i].z));
		if (v)a[i].x/=v,a[i].y/=v,a[i].z/=v;
		if (a[i].x){
			if (a[i].x<0)a[i].x*=-1,a[i].y*=-1,a[i].z*=-1;
		}else
		if (a[i].y){
			if (a[i].y<0)a[i].x*=-1,a[i].y*=-1,a[i].z*=-1;
		}else
		if (a[i].z<0)a[i].z*=-1;
	}
	sort(a+2,a+n+1,cmp);
	int ans=1;
	if (n==1)ans=0;
	for (int i=3;i<=n;i++)
		if (a[i].x!=a[i-1].x||a[i].y!=a[i-1].y||a[i].z!=a[i-1].z)ans++;
	printf("%d\n",ans);
	return 0;
}
