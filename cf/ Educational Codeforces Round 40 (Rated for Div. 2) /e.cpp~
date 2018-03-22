#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
typedef long double ld;
int n,T,toth,totc;
ld ans;
int a[N][2];
struct node{
	int v,T;
}hot[N],cold[N];
bool cmp(const node&a,const node&b){
	return a.T<b.T;
}
void get(node*a,ld v,int tot){
	for (int i=1;i<=tot;i++){
		ld s=min((ld)a[i].v,v/a[i].T);
		ans+=s;
		v-=s*a[i].T;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>T;
	ld allh=0,allc=0,allhv=0,allcv=0;
	for (int i=1;i<=n;i++)cin>>a[i][0];
	for (int i=1;i<=n;i++)cin>>a[i][1];
	for (int i=1;i<=n;i++){
		int x,y;
		x=a[i][0],y=a[i][1];
		if (y==T)ans+=x;
		else
		if (y>T){
			hot[++toth].T=y-T;
			hot[toth].v=x;
			allh+=(ld)x*(y-T);
			allhv+=x;
		}else{
			cold[++totc].T=T-y;
			cold[totc].v=x;
			allc+=(ld)x*(T-y);
			allcv+=x;
		}
	}
	sort(hot+1,hot+toth+1,cmp);
	sort(cold+1,cold+totc+1,cmp);
	if (allh<=allc){
		ans+=allhv;
		get(cold,allh,totc);
	}else{
		ans+=allcv;
		get(hot,allc,toth);
	}
	cout<<setprecision(10)<<ans;
	return 0;
}
