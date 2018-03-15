#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
#define MOD 100000007
#define A 1231232
using namespace std;
int a[N*2][2],g[N];
int d[N],v[N];
int n,sum;
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x){
	v[x]=1;
	for (int i=g[x];i;i=a[i][1])
		dfs(a[i][0]),v[x]^=((long long)v[a[i][0]]*A%MOD);
}
int work(){
	sum=0;
	for (int i=1;i<=n;i++)g[i]=0;
	int root;
	for (int i=1;i<=n;i++){
		int fa;
		scanf("%d",&fa);
		if (fa)ins(fa,i);
		else
			root=i;
	}
	dfs(root);
	return v[root];
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		work()==work()?printf("1\n"):printf("0\n");
	}
	return 0;
}
