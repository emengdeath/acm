#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int a[N];
int n;
bool issame(int x,int y,int xx,int yy){
	return x==xx&&y==yy;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	int x=0,y=0;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=2;i<=n;i++)
		if (abs(a[i]-a[i-1])!=1)
			x=abs(a[i]-a[i-1]);
	if (!x){
		for (int i=1;i<=n;i++)
			x=max(x,a[i]);
	}
	for (int i=1;i<=n;i++)
		y=max(y,a[i]/x+(a[i]%x!=0));
	for (int i=1;i<n;i++){
		bool bz=0;
		int xx=a[i]/x+(a[i]%x>0);
		int yy=a[i]%x;
		if (!yy)yy=x;
		int xxx=a[i+1]/x+(a[i+1]%x>0);
		int yyy=a[i+1]%x;
		if (!yyy)yyy=x;
		if (xx<y&&issame(xx+1,yy,xxx,yyy))bz=1;
		if (yy<x&&issame(xx,yy+1,xxx,yyy))bz=1;
		if (xx>1&&issame(xx-1,yy,xxx,yyy))bz=1;
		if (yy>1&&issame(xx,yy-1,xxx,yyy))bz=1;
		if (!bz){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	cout<<y<<' '<<x; 
	return 0;
}
