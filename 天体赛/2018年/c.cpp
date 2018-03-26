#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int ans[100];
int main(){
	ios::sync_with_stdio(false);
	cin>>a;
	cin>>b;
	cin>>c;
	for (int i=1;i<=max(c.size(),b.size());i++){
		int v,u;
		if (i<=b.size())v=b[b.size()-i]-'0';
		else
			v=0;
		if (i<=c.size())u=c[c.size()-i]-'0';
		else
			u=0;
		ans[a.size()-i+1]=u+v;
	}
	for (int i=a.size();i>=1;i--){
		int v=a[i-1]-'0';
		if (!v)v=10;
		if (i)ans[i-1]+=ans[i]/v,ans[i]%=v;
	}
	bool sig=0;
	for (int i=0;i<=a.size();i++)
		if (ans[i])sig=1,cout<<ans[i];
		else
			if (sig)cout<<ans[i];
	if (!sig)cout<<'0';
	return 0;
}
