#include<bits/stdc++.h>
using namespace std;
char s[10000];
int n,m;
char map1[2000][2000];
int main(){
	int n;
	scanf("%d\n",&n);
	gets(s);
	int len=strlen(s)-1;
	m=(len+1)/n+((len+1)%n>0);
	int x=0,y=0;
	for (int i=0;i<=len;i++){
		map1[x][y]=s[i];
		++x;
		if (x==n){
			x=0,y++;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)
			if (!map1[i][m-j-1])cout<<' ';
			else
				cout<<map1[i][m-j-1];
		if (i<n-1)cout<<endl;
	}
	return 0;
}
