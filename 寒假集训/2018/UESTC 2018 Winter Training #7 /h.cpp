#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000
#define M 100000
#include<cstring>
using namespace std;
const int b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int f[N][N],g[N][N],dis[N][N],to[27][N],num[N][N],d[M][2],dis1[N][N];
char map[N][N];
int n,m,ans;
char step[N];
int turn(char c){
	if (c=='@')return 0;
	if ('A'<=c&&c<='Z')return c-'A'+1;
	return -1; 
}
void bfs(int x,int y){
	int l=0,r=1;
	d[1][0]=x,d[1][1]=y;
	while (l!=r){
		++l;
		for (int i=0;i<4;i++){
			int x=d[l][0]+b[i][0],y=d[l][1]+b[i][1];
			if (!x||!y||x>n||y>m||map[x][y]=='#'||dis[x][y])continue;
			dis[x][y]=dis[d[l][0]][d[l][1]]+1;
			if (map[x][y]=='@'||map[x][y]=='.'){
				d[++r][0]=x;
				d[r][1]=y;
			}
		}
	}
}
void bfs1(){
	int l=0,r=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (map[i][j]=='@'){
				d[++r][0]=i;
				d[r][1]=j;
				dis1[i][j]=1;
			}else dis1[i][j]=0;
	while (l!=r){
		++l;
		for (int i=0;i<4;i++){
			int x=d[l][0]+b[i][0],y=d[l][1]+b[i][1];
			if (!x||!y||x>n||y>m||map[x][y]=='#'||dis1[x][y])continue;
			dis1[x][y]=dis1[d[l][0]][d[l][1]]+1;
			d[++r][0]=x;
			d[r][1]=y;
		}
	}
}
int main(){
	freopen("h.in","r",stdin);	
	int T;
	scanf("%d",&T);
	while (T--){
		ans=-1;
		scanf("%d %d",&n,&m);	
		for (int i=0;i<27;i++)to[i][0]=0;
		int calc=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				scanf(" %c",&map[i][j]);
				if (turn(map[i][j])>=0){
					num[i][j]=++calc;
					int x=turn(map[i][j]);
					to[x][++to[x][0]]=calc;
				}else num[i][j]=0;
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (num[i][j]){
					for (int i1=1;i1<=n;i1++)
						for (int j1=1;j1<=m;j1++)
							dis[i1][j1]=0;
					dis[i][j]=1;
					bfs(i,j);
					for (int i1=1;i1<=n;i1++)
						for (int j1=1;j1<=m;j1++)
							g[num[i][j]][num[i1][j1]]=dis[i1][j1]-1;
				}
		int q;
		scanf("%d",&q);
		bfs1();
		while (q--){
			scanf("%s",step+1);
			int tot=strlen(step+1);
			step[0]='@';
			for (int i=0;i<=tot;i++){
				step[i]=turn(step[i]);
				for (int j=1;j<=calc;j++)	
					f[i][j]=-1;
			}
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
					if (num[i][j])f[0][num[i][j]]=dis1[i][j]-1;
			for (int i=1;i<=tot;i++){
				int x=step[i-1],y=step[i];
				if (i==1){
					for (int x=1;x<27;x++)		
					for (int j=1;j<=to[x][0];j++){
						int xx=to[x][j];
						if (f[i-1][xx]!=-1)
						for (int k=1;k<=to[y][0];k++){
							int yy=to[y][k];
							if (g[xx][yy]!=-1){
								int v=g[xx][yy]+f[i-1][xx];
								if (f[i][yy]==-1||f[i][yy]>v)
									f[i][yy]=v;			
							}
						}
					}
				}else
				for (int j=1;j<=to[x][0];j++){
					int xx=to[x][j];
					if (f[i-1][xx]!=-1)
					for (int k=1;k<=to[y][0];k++){
						int yy=to[y][k];
						if (g[xx][yy]!=-1){
							int v=g[xx][yy]+f[i-1][xx];
							if (f[i][yy]==-1||f[i][yy]>v)
								f[i][yy]=v;			
						}
					}
				}
			}
			for (int i=1;i<=calc;i++)
				if (f[tot][i]!=-1){
					if (ans==-1||ans>f[tot][i])ans=f[tot][i];
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
