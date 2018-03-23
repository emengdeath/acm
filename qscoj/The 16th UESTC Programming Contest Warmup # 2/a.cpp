#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
const int N=100000;
int n;
string a[N];
bool cmp(string &a,string&b){
	return a+b>b+a;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}


