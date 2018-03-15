#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
bool c[26];
char s[N],ans[N];
int n,k;
char mx,mn;
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	mn=25;
	for (int i=1;i<=n;i++){c[s[i]-='a']=1;mx=max(s[i],mx);mn=min(mn,s[i]);}
	if (n>=k){
		int x=k;
		while (s[x]==mx)x--;
		for (int i=1;i<x;i++)ans[i]=s[i];
		int cc=s[x];
		while (!c[++cc]);
		ans[x]=cc;
		for (int i=x+1;i<=k;i++)ans[i]=mn;
	}else{
		for (int i=1;i<=n;i++)ans[i]=s[i];
		for (int i=n+1;i<=k;i++)ans[i]=mn;
	}
	for (int i=1;i<=k;i++)printf("%c",ans[i]+'a');
	return 0;
}
