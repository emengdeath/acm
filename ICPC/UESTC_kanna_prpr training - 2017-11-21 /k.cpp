#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000
using namespace std;
bool map[N][N];
int n,m,k;
int main(){
	freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int ansx=0,ansy=0;
	for (int i=1;i<=(n+1)/2;i++)
		for (int j=1;j<=(m+1)/2;j++)
			if (j*i==k)ansx=i,ansy=j;
	if (ansx*ansy!=k)printf("Impossible");
	else{
		for (int i=1;i<=ansx-1;i++)
			for (int j=1;j<=m;j++)
				map[i*2][j]=1;
		for (int j=1;j<=ansy-1;j++)
			for (int i=1;i<=n;i++)
				map[i][j+j]=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				if (map[i][j])printf("#");
				else
					printf(".");
			printf("\n");
		}
	}
	return 0;
}
