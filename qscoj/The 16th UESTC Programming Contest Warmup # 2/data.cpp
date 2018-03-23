#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("j.in","w",stdout);
	srand((int)time(0));
	int n=100;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%10000;
	//	if (rand()&1)x=-x;
		cout<<x<<' ';
	}
	return 0;
}
