#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000
using namespace std;
struct node{
	int cost,num;
}a[N],now,d[N];
long long f[2][10001];
bool sig[2][10001];
int n,w,b,x;
int main(){
	scanf("%d %d %d %d",&n,&w,&b,&x);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].num);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].cost);
	bool bz1=1,bz=0;
	f[0][0]=w;
	sig[0][0]=1;
	for (int i=1;i<=n;i++,swap(bz,bz1))
		for (int j=0;j<=10000;j++)
			if (sig[bz][j]){
				int sum=j;
				long long v=f[bz][j];
				while (1){
					f[bz1][sum]=max(f[bz1][sum],min(v+x,(long long)sum*b+w));
					sig[bz1][sum]=1;
					++sum;
					if (sum-j>a[i].num)break;
					if (v-a[i].cost<0)break;
					v=v-a[i].cost;
				}
				sig[bz][j]=0;
				f[bz][j]=0;
			}
	for (int i=10000;i>=0;i--)
		if (sig[bz][i]){
			printf("%d\n",i);
			break;
		}	
	return 0;
}
