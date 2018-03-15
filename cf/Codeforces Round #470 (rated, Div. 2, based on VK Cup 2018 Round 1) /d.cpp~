#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 300000
using namespace std;
struct node{
	int son[2];
	int sum;
}f[N*30];
int a[N],p[N];
int n,calc;
void ins(int x,int y,int z){
	while (z){
		f[x].sum++;
		bool sig=((y&z)>0);
		if (!f[x].son[sig])f[x].son[sig]=++calc;
		x=f[x].son[sig];
		z/=2;
	}
	f[x].sum++;
}
int get(int x,int y,int z){
	int ans=0;
	while (z){
		f[x].sum--;
		bool sig=((y&z)>0);
		if (f[x].son[sig]&&f[f[x].son[sig]].sum)x=f[x].son[sig];
		else
			x=f[x].son[sig^1],ans+=z;
		z/=2;
	}
	f[x].sum--;
	return ans;
}
int main(){
	scanf("%d",&n);
	calc=1;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)scanf("%d",&p[i]),ins(1,p[i],(1<<29));
	for (int i=0;i<n;i++)
		printf("%d ",get(1,a[i],(1<<29)));
	return 0;
}
