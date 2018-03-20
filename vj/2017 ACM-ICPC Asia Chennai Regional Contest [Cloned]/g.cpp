#include<bits/stdc++.h>
#define N 200000
#define MOD 1000000007
using namespace std;
long long a[N];
int main(){
	std::ios::sync_with_stdio(false); 
	int T;
	cin>>T;
	a[1]=a[2]=1;
	long long s=2;
	for (int i=3;i<N;i++){
		s=(long long)(s*2)%MOD;
		a[i]=(long long)(a[i-1]*((s-1+MOD)%MOD))%MOD;
	}
	while (T--){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
