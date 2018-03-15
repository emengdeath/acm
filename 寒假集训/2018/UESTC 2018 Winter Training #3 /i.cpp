#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int a[N];
bool f[2][21][21][2][2];
bool help[2][21][21];
int n,m;
int turn(int x){
	int y=1,z=1;
	bool sig=1;
	while (y*10<=x)y*=10;
	while (y){
		if (x/y%10!=x/z%10){
			sig=0;
			break;
		}
		y/=10;
		z*=10;
	}
	int sig2=2;
	while (x){
		if (x%10!=4&&x%10!=7){
			sig2=0;
			break;
		}
		x/=10;
	}
	return sig+sig2;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=turn(a[i]);
	if (a[1]&1)f[0][0][m][0][1]=1;
	if (a[1]&2)f[0][m][0][1][0]=1;
	help[0][0][m]=help[0][m][0]=1;
	bool bz=0,bz1=1;
	for (int i=1;i<n;i++,swap(bz,bz1))
		for (int j=0;j<=m;j++)
			for (int k=0;k<=m;k++)
				if (help[bz][j][k]){
					for (int j1=0;j1<=1;j1++)
						for (int k1=0;k1<=1;k1++)
							if (f[bz][j][k][j1][k1]){
								if (a[i+1]&1){
									if (!(k+1>=m&&!k1)){
										f[bz1][0][min(k+1,m)][j+1<=m][k1]=1;
										help[bz1][0][min(k+1,m)]=1;
									}
								}
								if (a[i+1]&2){
									if (!(j+1>=m&&!j1)){
										f[bz1][min(j+1,m)][0][j1][k+1<=m]=1;
										help[bz1][min(j+1,m)][0]=1;
									}
								}
								f[bz][j][k][j1][k1]=0;
							}
					help[bz][j][k]=0;
				}
	for (int j=0;j<=m;j++)
		for (int k=0;k<=m;k++)
			for (int j1=0;j1<=1;j1++)
				for (int k1=0;k1<=1;k1++)
					if (f[bz][j][k][j1][k1]){
						if (j<m&&!j1)continue;
						if (k<m&&!k1)continue;
						printf("Yes");
						return 0;
					}
	printf("No\n");
	return 0;
}
