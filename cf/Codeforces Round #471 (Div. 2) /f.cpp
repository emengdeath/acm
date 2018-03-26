#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3*1e5+2;
vector<int>f[N],f1[N];
int a[N*2][2],g[N],b[N],d[N];
int n;
ll ans;
void ins(int x,int y){
	static int sum=1;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x,int fa){
	int sum=0;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa)
			dfs(a[i][0],x),++sum;
	int totd=0;
	int mx=0;
	for (int i=1;;i++){
		int totb=0;
		for (int j=g[x];j;j=a[j][1])
			if (a[j][0]!=fa&&f[a[j][0]].size()>=i&&f[a[j][0]][i-1]==i){
				b[++totb]=f[a[j][0]][i-1];
			}
		if (totb<i){
			if (sum>=i)
				f[x].push_back(2),f1[x].push_back(2);
			break;
		}
		sort(b+1,b+totb+1);
		f[x].push_back(b[totb-i+1]+1);
		if (f1)
		f1[x].push_back(b[totb-i+1]+1);
		
	}
	if (!f[x].size()){
		f[x].push_back(1);
		f1[x].push_back(1);
	}	
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa){
			for (int j=0;j<f1[a[i][0]].size();j++)
				if (j==f1[x].size())f1[x].push_back(f1[a[i][0]][j]);
				else	
					f1[x][j]=max(f1[x][j],f1[a[i][0]][j]);
		}
	for (int i=0;i<f1[x].size();i++)
		ans+=f1[x][i];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		ins(x,y),ins(y,x);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
