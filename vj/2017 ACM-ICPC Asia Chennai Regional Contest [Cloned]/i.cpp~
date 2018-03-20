#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--){
		string s;
		int n,k;
		cin>>n>>k;
		cin>>s;
		int sum[2]={};
		for (int i=0;i<s.size();i++)
			sum[isupper(s[i])>0]++;
		int sig=2*(sum[0]<=k)+(sum[1]<=k);
		cout<<(!sig?"none":(sig==1?"chef":(sig==2?"brother":"both")))<<endl;
	}
	return 0;
}
