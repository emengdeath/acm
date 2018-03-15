#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
int a[N][N];
bool map[N][N];
int n;
char s[N];
void up(int x,int y){
	if (!a[x][y])return;
	while (x-1&&!a[x-1][y])swap(a[x][y],a[x-1][y]),x--;
	if (x-1&&a[x-1][y]==a[x][y]&&!map[x-1][y])map[x-1][y]=1,a[x-1][y]*=2,a[x][y]=0;
}
void down(int x,int y){
	if (!a[x][y])return;
	while (x+1<=n&&!a[x+1][y])swap(a[x][y],a[x+1][y]),x++;
	if (x+1<=n&&a[x+1][y]==a[x][y]&&!map[x+1][y])
		a[x+1][y]*=2,a[x][y]=0,map[x+1][y]=1;
}
void left(int x,int y){
	if (!a[x][y])return;
	while (y-1&&!a[x][y-1])swap(a[x][y],a[x][y-1]),y--;
	if (y-1&&a[x][y-1]==a[x][y]&&!map[x][y-1])a[x][y-1]*=2,a[x][y]=0,map[x][y-1]=1;
}
void right(int x,int y){
	if (!a[x][y])return;
	while (y+1<=n&&!a[x][y+1])swap(a[x][y],a[x][y+1]),y++;
	if (y+1<=n&&a[x][y+1]==a[x][y]&&!map[x][y+1])a[x][y+1]*=2,a[x][y]=0,map[x][y+1]=1;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %s",&n,s);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),map[i][j]=0;
		if (s[0]=='u'){
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					up(i,j);
		}else
		if (s[0]=='d')
			for (int i=n;i;i--)
				for (int j=1;j<=n;j++)
					down(i,j);
		else
		if (s[0]=='l')
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					left(i,j);
		else
			for (int i=1;i<=n;i++)
				for (int j=n;j;j--)
					right(i,j);
		for (int i=1;i<=n;i++){
			printf("%d",a[i][1]);
			for (int j=2;j<=n;j++)
				printf(" %d",a[i][j]);
			printf("\n");		
		}
	}	
	return 0;
}
