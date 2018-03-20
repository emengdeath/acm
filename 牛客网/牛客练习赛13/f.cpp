#include<bits/stdc++.h>
#define N 400000
using namespace std;
int sum[4][N],sig[N];
int n,m;
pair<int,int>a[N];
int main(){
	std::ios::sync_with_stdio(false); 
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>a[i].first>>a[i].second;
	sort(a+1,a+m+1);
	for (int i=1;i<=m;i++){
		int v1=a[i].first+a[i].second,v2=a[i].first-a[i].second+1e5;
		if (sum[0][v1])sig[i]++;
		sum[0][v1]++;
		if (sum[1][v2])sig[i]++;
		sum[1][v2]++;
	}
	memset(sum,0,sizeof(sum));
	for (int i=m;i;i--){
		int v1=a[i].first+a[i].second,v2=a[i].first-a[i].second+1e5;
		if (sum[0][v1])sig[i]++;
		sum[0][v1]++;
		if (sum[1][v2])sig[i]++;
		sum[1][v2]++;
	}
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=m;i++){
		if (!sum[0][a[i].first]||sum[0][a[i].first]>a[i].second)
			sum[0][a[i].first]=a[i].second;
		sum[1][a[i].first]=max(sum[1][a[i].first],a[i].second);
		if (!sum[2][a[i].second]||sum[2][a[i].second]>a[i].first)
			sum[2][a[i].second]=a[i].first;
		sum[3][a[i].second]=max(sum[3][a[i].second],a[i].first);
	}
	for (int i=1;i<=m;i++){
		if (sum[0][a[i].first]&&sum[0][a[i].first]<a[i].second)sig[i]++;
		if (sum[1][a[i].first]>a[i].second)sig[i]++;
		if (sum[2][a[i].second]&&sum[2][a[i].second]<a[i].first)sig[i]++;
		if (sum[3][a[i].second]>a[i].first)sig[i]++;
	}
	int t[9]={};
	for (int i=1;i<=m;i++)
		t[sig[i]]++;
	for (int i=0;i<8;i++)
		cout<<t[i]<<' ';
	cout<<t[8];
	return 0;
}
