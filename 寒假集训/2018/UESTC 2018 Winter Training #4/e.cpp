#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000
using namespace std;
int step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int T,n,m,k,tot;
int a[N*N][2],q[N][2];
char map[N][N];
bool check(int xx,int yy,int x,int y,int c){
	if (xx==x&&yy==y)return 1;
	for (int i=1;i<=10;i++){
		if (map[x+step[c][0]][y+step[c][1]]=='#')c=(c+1)%4;
		else{
			x+=step[c][0],y+=step[c][1];
			if (xx==x&&yy==y)return 1;
			else
				return 0;
		}
	}
	return 0;
}
int main(){
	freopen("reduce.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d %d %d",&n,&m,&k);
		int x,y;
		char c;
		scanf("%d %d %c",&x,&y,&c);
		if (c=='U')c=0;
		else
		if (c=='D')c=2;
		else
		if (c=='R')c=1;
		else
			c=3;
		for (int i=1;i<=n;i++)
			scanf(" %s",map[i]+1);
		int xx=x,yy=y,cc=c;
		tot=0;
		for (int i=1;i<=k;i++){
			char c;
			scanf(" %c",&c);
			if (c=='R')q[i][0]=0;
			else{
				q[i][0]=1;
				scanf("%d",&q[i][1]);
			}
		}
		for (int i=1;i<=k;i++)
			if (!q[i][0])
				cc=(cc+1)%4;
			else{
				for (int j=1;j<=q[i][1];j++){
					while(map[xx+step[cc][0]][yy+step[cc][1]]=='#')cc=(cc+1)%4;
					xx+=step[cc][0],yy+=step[cc][1];
					a[++tot][0]=xx;a[tot][1]=yy;
				}
			}
		bool sig=0;
		int ans=0;
		for (int i=1;i<=tot;i++){
			bool sig1=0;
			while (!check(a[i][0],a[i][1],x,y,c)){
				sig1=1;
				ans++;
				c=(c+1)%4;
			}
			while (map[x+step[c][0]][y+step[c][1]]=='#')c=(c+1)%4;
			x+=step[c][0],y+=step[c][1];
			if (!sig1&&sig)continue;
			sig=1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
