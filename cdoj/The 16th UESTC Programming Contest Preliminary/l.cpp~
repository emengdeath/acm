#include<bits/stdc++.h>
using namespace std;
int T;
int check(int x,int n){
	if (x==1)return n<=2;
	if (!x)return n<=1;
	if (n<=1)return 1;
	return check(x-1,n/x+(n%x>0));
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		int l=1,r=1e9,mid,s=1e9;
		check(1,n);
		while (l<=r){
			if (check(mid=(l+r)/2,n))s=min(s,mid),r=mid-1;
			else
				l=mid+1;
		}
		cout<<s<<endl;
	}
	return 0;	
}
