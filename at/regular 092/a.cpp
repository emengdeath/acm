#include<bits/stdc++.h>
#define N 200
using namespace std;
int a[N*N][2],from[N],A[N][2],B[N][2],g[N];
bool bz[N];
void ins(int x,int y){
	static int sum=1;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
bool dfs(int x){
	for (int i=g[x];i;i=a[i][1])
		if (!from[a[i][0]]){
			from[a[i][0]]=x;
			return 1;
		}else{
			if (bz[a[i][0]])continue;
			bz[a[i][0]]=1;
			if (dfs(from[a[i][0]])){
				from[a[i][0]]=x;
				return 1;
			}
		}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>A[i][0]>>A[i][1];
	for (int i=1;i<=n;i++)cin>>B[i][0]>>B[i][1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (A[i][0]<B[j][0]&&A[i][1]<B[j][1])
				ins(i,j);
	int ans=0;
	for (int i=1;i<=n;i++){
		memset(bz,0,sizeof(bz));
		ans+=dfs(i);
	}
	cout<<ans;
	return 0;
}
