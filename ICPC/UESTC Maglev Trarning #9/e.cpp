#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000
#define M 2000000
using namespace std;
int f[N][4][3],ans[N];
bool bz[N][4][3];
int n,l,r;
int d[M+1][3];
void update(int x,int y,int z,int v){
	if (y>3||z>2||x==12345)return;
	if (!f[x][y][z]||f[x][y][z]>v){
		f[x][y][z]=v;
		if (!bz[x][y][z]){
			bz[x][y][z]=1;
			d[r=r%M+1][0]=x,d[r][1]=y,d[r][2]=z;
		}
	}
	if (!ans[x]||ans[x]>v)ans[x]=v;
}
void pre(){
	l=0,r=1;
	d[1][0]=12345;
	bz[12345][0][0]=1;
	while (l!=r){
		l=l%M+1;
		int x=1;
		int v=f[d[l][0]][d[l][1]][d[l][2]]+1;
		for (int i=1;i<=5;i++){
			update(d[l][0]-d[l][0]/x%10*x+(d[l][0]/x%10+1)%10*x,d[l][1]+1,d[l][2],v);
			update(d[l][0]-d[l][0]/x%10*x+(d[l][0]/x%10*2)%10*x,d[l][1],d[l][2]+1,v);
			if (i!=5)update(d[l][0]-d[l][0]/x%10*x-d[l][0]/(x*10)%10*(x*10)+d[l][0]/x%10*x*10+d[l][0]/(x*10)%10*x,d[l][1],d[l][2],v);
			x*=10;
		}
		bz[d[l][0]][d[l][1]][d[l][2]]=0;
	}
}
int main(){
	pre();
	while (scanf("%d",&n)!=EOF){
		(ans[n]||n==12345)?printf("%d\n",ans[n]):printf("-1\n");
	}
	return 0;
}
