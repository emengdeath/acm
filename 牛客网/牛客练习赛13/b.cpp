#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e9;
vector<long long>d;
void dfs(long long x){
	if (x>maxn)return;
	d.push_back(x);
	dfs(x*10+4),dfs(x*10+7);
}
int main(){
	int l,r;
	unsigned long long ans={};
	cin>>l>>r;
	dfs(0);
	sort(d.begin(),d.end());
	for (int i=0;i<d.size();i++)
		if (d[i]>=r){
			ans+=(long long)(r-l+1)*d[i];
			break;
		}else
		if (d[i]>=l){
			ans+=(long long)(d[i]-l+1)*d[i];
			l=d[i]+1;			
		}
	cout<<ans;
	return 0;
}
