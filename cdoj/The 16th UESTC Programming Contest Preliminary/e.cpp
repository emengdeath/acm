#include<bits/stdc++.h>
using namespace std;
int d[1000000];
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		d[0]=0;
		while (n--){
			char c;
			cin>>c;
			d[++d[0]]=c-'0';
			while (d[0]>1&&d[d[0]]==1&&d[d[0]-1]==0)d[0]-=2;
		}
		cout<<d[0]<<".000"<<endl;
	}
	return 0;
}	
