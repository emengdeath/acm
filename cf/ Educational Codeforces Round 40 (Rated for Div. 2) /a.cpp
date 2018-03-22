#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	int sum=n;
	for (int i=0;i+1<n;i++)
		if (s[i]!=s[i+1]){
			sum--;
			i++;
		}
	cout<<sum;
	return 0;
}
