#include<bits/stdc++.h>
using namespace std;
int sig[4];
int all;
int main(){
	std::ios::sync_with_stdio(false); 
	int T,n;
	cin>>T;
	while (T--){
		string s;
		memset(sig,0,sizeof(sig));
		cin>>n;
		all=0;
		while (n--){
			cin>>s;
			all+=s.size();
			if (s.size()==1||s[0]==s[1])
				sig[s[0]=='k']++;
			else
				sig[2+(s[0]=='k')]++;
		}
		sig[0]=min(sig[0],1);
		sig[1]=min(sig[1],1);
		int ans=0;
		if (sig[2]||sig[3]){
			int mn=min(sig[2],sig[3]),mx=max(sig[2],sig[3]);
			if (mn==mx)
				ans=mn*2+1;
			else
				ans=mn*2+(mx-mn)*2;
		}else
			ans=sig[0]+sig[1];
		cout<<all-ans<<endl;
	}
	return 0;
}
