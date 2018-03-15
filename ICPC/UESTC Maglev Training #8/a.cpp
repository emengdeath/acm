#include<algorithm>
#include<cstdio>
#include<iostream>
#define N 1000000
#include<cstring>
using namespace std;
char s[N];
int T,n;
long long ans;
int len[N];
struct node{
	int x,y;
}a[N];
int f[N*4];
bool cmp(const node&a,const node&b){
	return a.y<b.y;
}
void ins(int l,int r,int s,int ll){
	f[s]++;
	if (l==r)return;
	if ((l+r)/2>=ll)ins(l,(l+r)/2,s+s,ll);
	else
		ins((l+r)/2+1,r,s+s+1,ll);
}
int get(int l,int r,int s,int ll,int rr){
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s];
	return get(l,(l+r)/2,s+s,ll,rr)+get((l+r)/2+1,r,s+s+1,ll,rr);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf(" %s",s+1);
		n=strlen(s+1);
		s[0]='~',s[n+1]='!';
		int x=0,k=0;
		for (int i=1;i<=n;i++){
			if (k>=i)len[i]=min(len[x+x-i],k-i);
			else
			 	len[i]=0;
			while (s[i+len[i]+1]==s[i-len[i]-1])len[i]++;
			if (len[i]+i>=k)k=len[i]+i,x=i;
			a[i].x=i,a[i].y=i-len[i];
		}
		for (int i=1;i<=4*n;i++)f[i]=0;
		sort(a+1,a+n+1,cmp);
		int l=1;
		ans=0;
		for (int i=1;i<=n;i++){
			while (l<=n&&a[l].y<=i)ins(1,n,1,a[l].x),l++;
			ans+=get(1,n,1,i+1,i+len[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
