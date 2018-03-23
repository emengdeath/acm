#include<bits/stdc++.h>
#define N 201
using namespace std;
const int MAXN=1e8;
int f[2][N][3][2];
int	n;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<2;i++)
		for (int j=0;j<N;j++)
			for (int k=0;k<3;k++)
				for (int l=0;l<2;l++)
					f[i][j][k][l]=MAXN;
	bool bz=0,bz1=1;
	for (int i=1;i<=n;i++,swap(bz,bz1)){
		int x;
		cin>>x;
		for (int j=0;j<N;j++)
			for (int k=0;k<2;k++){
				if (!k){
					int v=min(f[bz][j][k][0],f[bz][j][k][1]);
					f[bz][j][k][0]=f[bz][j][k][1]=v;
				}
				if (j<x){
					f[bz1][x][1][1]=min(f[bz1][x][1][1],f[bz][j][k][0]);
					f[bz1][x][k+1][1]=min(f[bz1][x][k+1][1],f[bz][j][k][1]);
				}else
				if (j==x){
					f[bz1][x][0][0]=min(f[bz1][x][0][0],min(f[bz][j][k][0],f[bz][j][k][1]));
					f[bz1][x][0][1]=min(f[bz1][x][0][1],min(f[bz][j][k][0],f[bz][j][k][1]));
				}else{
					f[bz1][x][k+1][0]=min(f[bz1][x][k+1][0],f[bz][j][k][0]);
					f[bz1][x][1][0]=min(f[bz1][x][1][0],f[bz][j][k][1]);
				}
				f[bz1][j][k][0]=min(f[bz1][j][k][0],f[bz][j][k][0]+1);
				f[bz1][j][k][1]=min(f[bz1][j][k][1],f[bz][j][k][1]+1);
				f[bz][j][k][0]=f[bz][j][k][1]=MAXN;
			}
		f[bz1][x][0][0]=min(f[bz1][x][0][0],i-1);
		f[bz1][x][0][1]=min(f[bz1][x][0][1],i-1);	
	}
	int ans=n;
	for (int i=0;i<N;i++)
		for (int j=0;j<2;j++)
			ans=min(ans,min(f[bz][i][j][0],f[bz][i][j][1]));
	cout<<ans;
	return 0;
}
