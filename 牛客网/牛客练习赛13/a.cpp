#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int sum[10]={};
	for (int i=0;i<s.size();i++)
		sum[s[i]-'0']++;
	(sum[4]&&sum[4]>=sum[7])?cout<<4:(!sum[7]?cout<<-1:cout<<7);
	return 0;
}
