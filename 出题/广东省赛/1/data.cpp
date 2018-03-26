#include<bits/stdc++.h>
using namespace std;
const int n=1000,len=100;
int q=1000;
const int MAXN=100000;
int a[n+1];
int main(){
	ios::sync_with_stdio(false);
	srand((int)time(0));
	int l=rand()%len,r=rand()%len;
	for (int i=1;i<=n;i++)a[i]=i;
	random_shuffle(a+1,a+n+1);
	if (l>r)swap(l,r);
	cout<<n<<' '<<q<<' '<<l<<' '<<r<<endl;
	for (int i=1;i<=n;i++)
		cout<<rand()%MAXN<<' ';
	cout<<endl;
	for (int i=2;i<=n;i++)
		cout<<a[i]<<' '<<a[rand()%(i-1)+1]<<endl;
	while (q--){
		cout<<rand()%n+1<<' '<<rand()%n+1<<' '<<rand()%MAXN<<endl;
	}
	return 0;
}
