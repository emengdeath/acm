#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000000
using namespace std;
struct node{
	int mn,sum;
	int sig;
}f[N*4];
int n;
int a[N];
void down(int l,int r,int s){
	if (f[s].sig){
		f[s].mn=max(0,f[s].mn-f[s].sig);
		if (l!=r){
			if (f[s+s].sum)f[s+s].sig+=f[s].sig;
			if (f[s+s+1].sum)f[s+s+1].sig+=f[s].sig;
		}
		f[s].sig=0;
	}
}
void ins(int l,int r,int s,int ll,int v){
	down(l,r,s);
	if (!f[s].mn||f[s].mn>v)f[s].mn=v;
	f[s].sum++;
	if (l==r)return;
	if ((l+r)/2>=ll)ins(l,(l+r)/2,s+s,ll,v);
	else
		ins((l+r)/2+1,r,s+s+1,ll,v);
}
void del(int l,int r,int s){
	if (l==r){
		f[s].sum=f[s].mn=0;
		return;
	}
	down(l,(l+r)/2,s+s),down((l+r)/2+1,r,s+s+1);
	if (f[s].mn==f[s+s].mn)del(l,(l+r)/2,s+s);
	else
		del((l+r)/2+1,r,s+s+1);
	if (!f[s+s].mn)f[s].mn=f[s+s+1].mn;
	else
	if (!f[s+s+1].mn)f[s].mn=f[s+s].mn;
	else
	f[s].mn=min(f[s+s].mn,f[s+s+1].mn);
	f[s].sum=f[s+s].sum+f[s+s+1].sum;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int T;
		scanf("%d",&T);
		if (a[i])ins(1,n,1,i,a[i]);
		long long ans=0;
		down(1,n,1);
		while (f[1].sum&&f[1].mn<=T){
			ans+=f[1].mn;
			del(1,n,1);
		}
		f[1].sig+=T;
		ans+=(long long)f[1].sum*T;
		printf("%I64d ",ans);
	}
	return 0;
}
