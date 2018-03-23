#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	srand((int)time(0));
	int T=1000;
	cout<<T<<endl;
	int all=1e6;
	while (T--){
		int n;
		do{
			n=rand()%min(all,(int)1000)+1;
		}while (all-n-T<0);
		if (!T)n=all;
		all-=n;
		cout<<n<<endl;
		int sig=rand()%((1<<4)-1)+1;
		for (int i=1;i<=n;i++){
			int x;
			do{
				x=rand()%4;
			}while (!(sig&(1<<x)));
			if (!x){
				if (rand()&1)cout<<"kk ";
				else
					cout<<"k ";
			}else
			if (x==1){
				if (rand()&1)cout<<"pp ";
				else
					cout<<"p ";
			}else
			if (x==2){
				cout<<"kp ";
			}else
				cout<<"pk ";
		}
		cout<<endl;
	}
	return 0;
}
