#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10];
int main(){
	while (scanf(" %s",s+1)){
		int n=strlen(s+1);
		int v=0;
		for (int i=1;i<=n;i++)
			if (s[i]=='.')v=v*3+1;
			else
				v=v*3+2;
		printf("%d\n",v);
	}
	return 0;
}
