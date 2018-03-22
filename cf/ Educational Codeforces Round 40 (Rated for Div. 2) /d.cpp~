#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int a[N*2][2],g[N],dis[2][N],d[N];
bool link[N][N];
int n,m,s,t;
void ins(int x,int y){
	static int sum=0;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void spfa(int*dis,int s){
	int l=0,r=0;
	d[++r]=s;
	dis[s]=1;
	while (l!=r){
		for (int i=g[d[++l]];i;i=a[i][1])
			if (!dis[a[i][0]]){
				dis[d[++r]=a[i][0]]=dis[d[l]]+1;
			}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		ins(x,y),ins(y,x);
		link[x][y]=link[y][x]=1;
	}
	spfa(dis[0],s);
	spfa(dis[1],t);
	int sum=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (!link[i][j]&&min(dis[0][i]+dis[1][j]-2+1,dis[0][j]+dis[1][i]-2+1)>=dis[0][t]-1)sum++;
	cout<<sum;
	return 0;
}
