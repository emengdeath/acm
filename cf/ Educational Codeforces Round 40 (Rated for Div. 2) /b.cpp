#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string s;
	int n,sig=0;
	cin>>n;
	cin>>s;
	for (int i=1;i<=n/2&&i+i-1<n;i++){
		bool bz=1;
		for (int j=0;j<i;j++)
			if (s[j]!=s[j+i])bz=0;
		if (bz)sig=i;
	}	
	
	sig?cout<<n-sig+1:cout<<n;
	return 0;
}
