#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void work(int&x,int len){
	if (x!=1)printf(" ");
	printf("%d",x+len-1);
	for (int i=0;i<len-1;i++)printf(" %d",x+i);
	x+=len;
}
int main(){
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	for (int i=0;(long long)i*l<=n;i++){
		int j=(n-i*l)/r;
		if (j*r+i*l==n){
			int x=1;
			for (int k=1;k<=i;k++)work(x,l);
			for (int k=1;k<=j;k++)work(x,r);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
