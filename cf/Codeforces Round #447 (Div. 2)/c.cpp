#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 10000000
#include<cmath>
using namespace std;
struct node{
	int x,y;
}a[N];
int n;
int b[N];
bool bz[N];
int gcd(int x,int y){
	return !x?y:gcd(y%x,x);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].x),bz[a[i].x]=1;
	for (int i=1;i<=n;i++){
		int x=a[i].x;
		for (int j=1;j<=sqrt(a[i].x);j++)
			if (!(a[i].x%j)){
				if (bz[j]&&!(a[i].y))a[i].y=j;
				if (bz[a[i].x/j])x=min(x,a[i].x/j);
			}
		if (!a[i].y)a[i].y=x;
		b[++b[0]]=a[i].y;
		b[++b[0]]=a[i].x;
		b[++b[0]]=a[i].y;
	}
	for (int i=1;i<=b[0];i++){
		int x=b[i];
		for (int j=i;j<=b[0];j++){
			if (!bz[x]){
				printf("-1");
				return 0;
			}
			x=gcd(x,b[j]);
		}
	}
	printf("%d\n",b[0]);
	printf("%d",b[1]);
	for (int i=2;i<=b[0];i++)
		printf(" %d",b[i]);
	return 0;
}
