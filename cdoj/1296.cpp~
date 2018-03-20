#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,k;
int f[1<<N];
int fa[N];
pair<int,int>E[N*N],Q[N*N];
int check(int v){
	int sig=0;
	for (int i=1;i<=k;i++){
		if (((v&(1<<(Q[i].first-1)))>0)!=((v&(1<<(Q[i].second-1)))>0))return 0;
		sig|=((v&(1<<(Q[i].first-1)))>0);
		sig|=((v&(1<<(Q[i].second-1)))>0);
	}
	return 1+sig;
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int build(int v){
	int sum=0,sum1=0;
	for (int i=1;i<=n;i++)
		if (v&(1<<(i-1)))
			fa[i]=i,sum++;
	for (int i=1;i<=m;i++)
		if ((v&(1<<(E[i].second-1)))&&(v&(1<<(E[i].first-1))))
			if (getfa(E[i].second)!=getfa(E[i].first)){
				sum1++;
				fa[fa[E[i].second]]=E[i].first;
			}
	return sum1==sum-1?sum1:-1;
}
void dfs(int x,int y,int z){
	if (f[y]!=-1&&f[x-y]!=-1&&(f[x]==-1||f[x]>f[y]+f[x-y]))f[x]=f[y]+f[x-y];
	while (1){
		while (z<=n&&!(x&(1<<(z-1))))z++;
		if (z>n)return;
		dfs(x,y+(1<<(z-1)),z+1);
		z++;
	}
}
int main(){
	std::ios::sync_with_stdio(false); 
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>E[i].first>>E[i].second;
	for (int i=1;i<=k;i++)
		cin>>Q[i].first>>Q[i].second;
	f[0]=0;
	for (int i=1;i<(1<<n);i++){
		f[i]=-1;
		int sig=check(i);
		if (!sig)continue;
		if (sig==1){
			f[i]=0;
			continue;
		}
		int sum=build(i);
		if (sum!=-1)f[i]=sum;
		dfs(i,0,1);
	}
	f[(1<<n)-1]==-1?cout<<-1:cout<<m-f[(1<<n)-1];
	return 0;
}
