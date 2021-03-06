#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1000001
using namespace std;
int a[N];
int f[N];
int n,tot;
int b[N],c[N];
int main(){
//	freopen("equal.in","r",stdin);
//	freopen("equal.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int all=0;
	for (int i=1;i<N;i++)
		if (a[i])c[++all]=a[i];
	for (int i=0;i<=n;i++)
		f[i]=all;
	b[0]=0;
	for (int i=1;i<N;i++)
		if (a[i]){
			for (int j=2;(long long)j*i<=N;j++)
				if (a[i*j]){
					b[++b[0]]=a[i];
					break;
				}
		}
	sort(b+1,b+b[0]+1);
	int x=0;
	for (int i=1;i<=b[0];i++){
		x+=b[i];
		f[x]=min(f[x],all-i);
	}
	sort(c+1,c+all+1);
	x=c[1];
	for (int i=2;i<=all;i++){
		x+=c[i];
		f[x]=min(f[x],all-i+1);
	}
	for (int i=1;i<=n;i++)
		f[i]=min(f[i],f[i-1]);
	for (int i=n;i;i--)
		f[i-1]=min(f[i-1],f[i]+1);
	printf("%d",f[0]);
	for (int i=1;i<=n;i++)
		printf(" %d",f[i]);
	return 0;
}
