#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000100
using namespace std;
int f[N];
int n,tot;
int b[3][2]={{1,2},{4,4},{7,3}};
int a[1000][2];
bool pre(int x,int y,int v){
	int z=1;
	while (x>=z){
		a[++tot][0]=z*v,a[tot][1]=y*z,x-=z,z*=2;
	}
	if (x)a[++tot][0]=x*v,a[tot][1]=x*y;
}
int main(){
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<3;i++)	
		pre(n/b[i][1],b[i][0],b[i][1]);
	f[0]=1;
	for (int i=1;i<=tot;i++)
		for (int j=n-a[i][0];j>=0;j--)
			if (f[j]&&(!f[j+a[i][0]]||f[j+a[i][0]]<f[j]+a[i][1]))
				f[j+a[i][0]]=f[j]+a[i][1];
	printf("%d\n",f[n]-1);
	return 0;
}
