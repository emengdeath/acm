#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
ui n,m;
ui a[10000],b[10000];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	ui ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			ui mn=a[i];
			for (int k=i;k<=j;k++)
				mn=min(mn,a[k]);
			ui v=0;
			for (int k=i;k<=j;k++)
				v^=a[k];
			ans+=(m>=mn*v);
		}
	cout<<ans;
	return 0;
}
