#include<bits/stdc++.h>
using namespace std;
int a[100][100][100];
int gcd(int x,int y){
	return !x?y:gcd(y%x,x);
}
int main(){
	freopen("input","r",stdin);
	for (int i=3;i<=8;i++){
		for (int j=1;j<=i;j++)
			for (int k=1;k<=i;k++)
				cin>>a[i][j][i-k+1];
		/*if (i!=3)
		for (int j=1;j<i;j++){
			for (int k=1;k<i;k++){
				if (!a[i-1][j][k]){
					cout<<"0/0\t";
				}else{
					int v=gcd(a[i-1][j][k],a[i][j][k]);
					cout<<a[i-1][j][k]/v<<'/'<<a[i][j][k]/v<<'\t';
				}
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	for (Iint)
	return 0;
}
