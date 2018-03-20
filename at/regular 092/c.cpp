#include<bits/stdc++.h>
#define N 1011
using namespace std;
typedef long long ll;
ll f[N][N];
int n;
int from[N][N],ans[N];
int dfs(int l,int r,int x){
	if (!from[l][r])return 0;
		x+=dfs(l,from[l][r]-1,x);
	int	x1=dfs(from[l][r]+1,r,x);
	if (l==1&&from[l][r]!=r&&f[from[l][r]+1][r]==f[l][r]){
		if (from[l][r]!=l)ans[++ans[0]]=from[l][r]-1-x,++x;
		ans[++ans[0]]=from[l][r]-x;
		x++;
	}else
	if (r==n&&from[l][r]!=l&&f[l][from[l][r]-1]==f[l][r]){
		if (from[l][r]!=r)ans[++ans[0]]=from[l][r]-x+1,++x1;
		ans[++ans[0]]=from[l][r]-x;
		x++;
	}else{
		ans[++ans[0]]=from[l][r]-x;
		if (from[l][r]==l||from[l][r]==r)x++;
		else
			x+=2;
	}
	return x1+x;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>f[i][i];
	for (int len=1;len<n;len++)
		for (int i=1;i+len<=n;i++){
			int j=i+len;
			f[i][j]=-1e17;
			if (i==1){
				f[i][j]=f[i+1][j];
				from[i][j]=i;
			}else
			if (i==n){
				f[i][j]=f[i][j-1];
				from[i][j]=j;
			}else{
				if (i+2<=j){
					f[i][j]=f[i+2][j]+f[i][i];
					from[i][j]=i+1;
				}
			}
			for (int k=i+1;k<j;k++){
				ll v=f[i][k-1]+f[k+1][j];
				if (v>f[i][j])f[i][j]=v,from[i][j]=k;
			}
			if (i==1){
				for (int k=i+1;k<j;k++){	
					ll v=f[k+1][j];
					if (v>f[i][j])f[i][j]=v,from[i][j]=k;
				}
			}
			if (j==n){
				for (int k=i+1;k<j;k++){	
					ll v=f[i][k-1];
					if (v>f[i][j])f[i][j]=v,from[i][j]=k;
				}
			}
			if (j==n&&f[i][j]<f[i][j-1])
				from[i][j]=j,f[i][j]=f[i][j-1];
		}
	cout<<f[1][n]<<endl;
	dfs(1,n,0);
	cout<<ans[0]<<endl;
	for (int i=1;i<=ans[0];i++)
		cout<<ans[i]<<endl;
	return 0;
}
