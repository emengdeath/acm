#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
#include<cstring>
using namespace std;
char s[N];
int a[N],b[N];
int n,ans;
int main(){
	scanf(" %s",s+1);
	n=strlen(s+1);
	int x=0;
	for (int i=1;i<=n;i++){
		a[i]=x;
		if (s[i]=='Q')x++;
	}
	x=0;
	for (int i=n;i;i--){
		b[i]=x;
		if (s[i]=='Q')x++;
	}
	for (int i=1;i<=n;i++)
		if (s[i]=='A')ans+=a[i]*b[i];
	printf("%d\n",ans);
	return 0;
}
