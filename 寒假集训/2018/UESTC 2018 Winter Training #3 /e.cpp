#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
#define MOD1 10000007
#define MOD2 10000009
#include<cstring>
using namespace std;
struct node{
	int x,y;
	node(int X=0,int Y=0){x=X,y=Y;}
}fa[N],fb[N],help[N];
char A[N],B[N];
int na,nb,m;
node operator+(node&a,int x){
	return node(((long long)a.x*255+x)%MOD1,((long long)a.y*255+x)%MOD2);
}
node operator-(node&a,node b){
	return node((a.x-b.x+MOD1)%MOD1,(a.y-b.y+MOD2)%MOD2);
}
node operator*(node&a,int x){
	return node(((long long)a.x*x)%MOD1,((long long)a.y*x)%MOD2);
}
node operator*(node&a,node b){
	return node(((long long)a.x*b.x)%MOD1,((long long)a.y*b.y)%MOD2);
}
node get(int l,int r){
	return fa[r]-fa[l-1]*help[r-l+1];
}
bool operator==(node a,node b){
	return a.x==b.x&&a.y==b.y;
}
bool check(int len){
	int s=0;
	for (int i=1;i+len-1<=na;i++)
		if (get(i,i+len-1)==fb[len])s++;
	return s>=m;
}
int main(){
	help[0]=node(1,1);
	for (int i=1;i<N;i++)help[i]=help[i-1]*255;
	gets(A);
	gets(B);
	scanf("%d",&m);
	na=strlen(A),nb=strlen(B);
	for (int i=1;i<=na;i++)fa[i]=fa[i-1]+A[i-1];
	for (int i=1;i<=nb;i++)fb[i]=fb[i-1]+B[i-1];
	int l=0,r=nb,mid,s=0;
	while (l<=r){
		if (check(mid=(l+r)/2))l=mid+1,s=max(s,mid);
		else
			r=mid-1;	
	}
	if (!s)
		printf("IMPOSSIBLE");
	else
		for (int i=0;i<s;i++)printf("%c",B[i]);
	return 0;
}
