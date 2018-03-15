#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define N 2000000
using namespace std;
struct node{
	int son[27];
	int len,fail;
	bool sig;
}tri[N];
char S[N];
int len,L,lst;
int in[N],d[N];
void add(int last,int c,bool sig){
	static int v,u,up,up1;
	v=++L;
	u=last;
	tri[v].len=tri[u].len+1;
	for (;u&&!tri[u].son[c];u=tri[u].fail)tri[u].son[c]=v;
	if (!u)tri[v].fail=1;
	else{
		up=tri[u].son[c];
		if (tri[up].len==tri[u].len+1)tri[v].fail=up;
		else{
			up1=++L;
			tri[up1]=tri[up];
			tri[up1].len=tri[u].len+1;
			tri[up].fail=tri[v].fail=up1;
			for (;u&&tri[u].son[c]==up;u=tri[u].fail)tri[u].son[c]=up1;
		}
	}
	tri[v].sig=sig;
	lst=v;
}
int main(){
	scanf(" %s",S+1);
	len=strlen(S+1);
	lst=1,L=1;
	for (int i=1;i<=len;i++)add(lst,S[i]-'a',0);
	scanf(" %s",S+1);
	len=strlen(S+1);
	add(lst,26,1);
	for (int i=1;i<=len;i++)add(lst,S[i]-'a',1);
	for (int i=1;i<=L;i++)in[tri[i].fail]++;
	int l=0,r=0;
	for (int i=1;i<=L;i++)
		if (!in[i])d[++r]=i;
	while (l!=r){
		++l;
		tri[tri[d[l]].fail].sig|=tri[d[l]].sig;
		if (!(--in[tri[d[l]].fail]))
			d[++r]=tri[d[l]].fail;
	}
	long long ans=0;
	for (int i=1;i<=L;i++)
		if (!tri[i].sig)
			ans+=tri[i].len-tri[tri[i].fail].len;
	printf("%lld\n",ans);
	return 0;
}
