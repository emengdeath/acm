#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
long double f[N][N];
bool bz[N][N];
int n,m;
void dfs(int x,int y){
	if (bz[x][y])return;
	bz[x][y]=1;
	if (!y){
		f[x][y]=n-x;
		return;
	}
	if (x){
		dfs(x-1,y-1);
		dfs(x,y-1);
		f[x][y]=(f[x-1][y-1]+f[x][y-1])/2;
	}else{
		dfs(x+1,y-1);
		dfs(x,y-1);
		f[x][y]=(f[x+1][y-1]+f[x][y-1])/2;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	dfs(n,m);
	printf("%.10f",(double)f[n][m]);
	return 0;
}
