#include<bits/stdc++.h>
#define N 10000
using namespace std;
int x[N];
int n,E;
int main(){
	ios::sync_with_stdio(false); 
	int T;
	cin>>T;
	while (T--){
		cin>>n>>E;
		int y=0,mx=1,mn=1;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			if (x[i]==E)y=i;
			if (x[i]<E)mn=i;
			if (x[i]>E)mx=i;
		}
		if (y){
			for (int i=1;i<=n;i++)
				if (i!=y)cout<<0<<' ';
				else
					cout<<1<<' ';
		}else{
			if (x[mn]>E||x[mx]<E){
				cout<<-1<<endl;
				continue;
			}
			double v1=((double)E-x[mx])/(x[mn]-x[mx]),v2=1-v1;
			for (int i=1;i<=n;i++)
				if (i==mn)cout<<setprecision(10)<<v1<<' ';
				else
				if (i==mx)cout<<setprecision(10)<<v2<<' ';
				else
					cout<<0<<' ';
		}
		cout<<endl;
	}
	return 0;
}
