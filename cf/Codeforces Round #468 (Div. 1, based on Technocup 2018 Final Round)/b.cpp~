#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 5001
#include<cstring>
using namespace std;
int bz[26][26][5001];
int n;
char s[N];
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)s[i]-='a';
	for (int i=0;i<n;i++){
		int x=(i+1)%n;
		int y=1;
		while (x!=i)
			bz[s[i]][s[x]][y]++,x=(x+1)%n,y++;
	}
	int ans=0;
	for (int i=0;i<26;i++){
		int s=0;
		for (int j=1;j<=n;j++){
			int s1=0;
			for (int k=0;k<26;k++)	s1+=(bz[i][k][j]==1);
			s=max(s,s1);	
		}
		ans+=s;
	}
	printf("%.9lf",(double)ans/n);
	return 0;
}
