#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
#define MOD 100000000
using namespace std;
int T,n;
struct node{
	int v[100];
}x,y;
struct node1{
	int x,y;
}a[N];
bool cmp(const node&a,const node&b){
	
}
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d",&n);
		for (int j=1;j<=n;j++){
			double x,y;
			scanf("%lf:%lf",&x,&y);
			a[j].x=y*1000;
			a[j].y=(x+y)*1000;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0;
		double v=0;
		for (int i=1;i<=n;i++){
			v+=a[i];
			if (v<=1)ans=i;
			else
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
