#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N][2];
int n,ans;
int mx[2],mn[2];
int get(int x,int y){
	return abs(a[x][0]-a[y][0])+abs(a[x][1]-a[y][1]);
}
int main(){
	freopen("intel.in","r",stdin);
	freopen("intel.out","w",stdout);
	mx[0]=mx[1]=-1e9;
	mn[0]=mn[1]=1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		mx[0]=max(mx[0],x);
		mn[0]=min(mn[0],x);
		mx[1]=max(mx[1],y);
		mn[1]=min(mn[1],y);
		a[i][0]=x,a[i][1]=y;
	}
	for (int i=1;i<=n;i++)
		ans+=get(i,i%n+1);
	printf("%d\n",ans-(mx[0]+mx[1]-mn[0]-mn[1])*2);
	return 0;
}
