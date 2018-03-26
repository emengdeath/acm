#include<bits/stdc++.h>
using namespace std;
int cnt[26];
string S;
int main(){
	ios::sync_with_stdio(false);
	cin>>S;
	int all=0;
	for (int i=0;i<26;i++)
		cin>>cnt[i],all+=cnt[i];
	int l=0;
	for (int i=0;i<S.size();i++){
		while (!cnt[S[i]-'a'])cnt[S[l]-'a']++,l++,all++;
		cnt[S[i]-'a']--,all--;
		if (!all&&l<i){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
