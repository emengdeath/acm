#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
char s[N][N];
int n,m,c;
bool work(int x,int y){
	if (!x||!y||x>n||y>m)return 0;
	if (s[x][y]=='W')return 1;
	if (s[x][y]=='.')s[x][y]='D';
	return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)scanf(" %c",&s[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='S')
				if (work(i-1,j)||work(i,j-1)||work(i+1,j)||work(i,j+1)){
					printf("No");
					return 0;
				}
	printf("Yes\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}
