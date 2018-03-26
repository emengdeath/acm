#include<bits/stdc++.h>
using namespace std;
int ans[20][20];
int d[20];
int check(int x,int y,int len){
	int s=0;
	while (s+x<=len&&y+s<=len&&d[s+x]==d[y+s])s++;
	return s;
}
void work(int len,int v){
	bool bz[20];
	memset(bz,0,sizeof(bz));
	for (int i=1;i<=len;i++)bz[d[i]]=1;
	for (int i=1;i<=v;i++)if (!bz[i])return;
	int s=0;
	for (int i=2;i<=len;i++)
		s=max(check(1,i,len),s);
	ans[v][s]++;
}
void dfs(int x,int len,int v){
	if (x>len){
		work(len,v);
		return;
	}
	for (int i=1;i<=v;i++)
		d[x]=i,dfs(x+1,len,v);
}
int main(){
	for (int i=1;i<=10;i++){
		memset(ans,0,sizeof(ans));
		for (int j=1;j<=i;j++)
			dfs(1,i,j);
		for (int j=1;j<=i;j++){
			for (int k=0;k<i;k++)
				cout<<ans[j][k]<<'\t';
			cout<<endl;
		}
	}
	return 0;
}
