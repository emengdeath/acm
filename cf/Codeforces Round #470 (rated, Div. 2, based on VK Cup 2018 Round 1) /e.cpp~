#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
#include<cstring>
using namespace std;
char s[N],s1[N];
int t[N],t1[N];
int n,m,T;
int f[N*2],g[N*2];
void build(char*S,int*f,int*t,int l,int r,int s){
	if (l==r){
		f[s]=(S[l]=='B'||S[l]=='C');
		if (!f[s])t[s]=1;
		return;
	}
	build(S,f,t,l,(l+r)/2,s+s),build(S,f,t,(l+r)/2+1,r,s+s+1);
	f[s]=(f[s+s]+f[s+s+1]);
	if (t[s+s+1]==r-(l+r)/2)t[s]=t[s+s+1]+t[s+s];
	else
		t[s]=t[s+s+1];
}
int get(int*f,int*t,int l,int r,int s,int ll,int rr,int&v){
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr){
		if (v==rr-r)v+=t[s];
		return f[s];
	}
	int s1=get(f,t,(l+r)/2+1,r,s+s+1,ll,rr,v);
	return s1+get(f,t,l,(l+r)/2,s+s,ll,rr,v);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",s1+1);
	m=strlen(s1+1);
	build(s,f,t,1,n,1);
	build(s1,g,t1,1,m,1);
	scanf("%d",&T);
	while (T--){
		int l,r,l1,r1;
		scanf("%d %d %d %d",&l,&r,&l1,&r1);
		int u1=0,u2=0;
		int v1=get(f,t,1,n,1,l,r,u1),v2=get(g,t1,1,m,1,l1,r1,u2);
		if (u2>u1){
			printf("0");
			continue;
		}
		if (!v1&&v2&&u1==u2){
			printf("0");
			continue;
		}
		u1=(u1-u2)%3+u2;
		if (u1-u2){
			v1+=2;
			u1=u2;
		}
		u1%=3,u2%=3;
		while (u1!=u2)(u1+=1)%=3,v1+=2;
		v1<=v2&&(v1&1)==(v2&1)?printf("1"):printf("0");
	}
	return 0;
}
