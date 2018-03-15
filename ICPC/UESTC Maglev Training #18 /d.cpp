#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
#include<cstring>
using namespace std;
char s[N],t[N];
int main(){
	scanf(" %s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
		t[i]=s[i];
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
		while (s[i]!=t[i]){
			for (int j=1;j<=n;j++)
				if (t[j]==s[i]&&s[j]!=t[j]){
					if (s[j]<s[i])
						printf("%d %d\n",i,j);
					else
						printf("%d %d\n",j,i);
					swap(s[j],s[i]);
					break;
				}	
		}
	return 0;
}
