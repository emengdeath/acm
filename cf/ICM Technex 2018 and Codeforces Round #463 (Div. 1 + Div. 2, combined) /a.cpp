#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000
#include<cstring>
using namespace std;
char s[N];
int main(){
	scanf(" %s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++)printf("%c",s[i]);
	for (int i=0;i<n;i++)printf("%c",s[n-i-1]);
	return 0;
}
