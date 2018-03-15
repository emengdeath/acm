#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 1000007
#define N 300000
#include<cstring>
#define hash dodo
using namespace std;
const int mod=1000000007;
int help[N],f[N];
char s[N];
char s1[N];
int l[N],r[N];
int calc,n,T,L;
char ans[N];
bool ansbz;
struct node{
	int v,next,bz;
}hash[MOD+MOD];
int get(int l,int r){
	return (f[r]-(long long)f[l-1]*help[r-l+1]%mod+mod)%mod;
}
void ins(int v){
	 int y=v%MOD;
	 while (hash[y].v!=v&&hash[y].bz==calc&&hash[y].next)y=hash[y].next;
	 if (hash[y].v==v&&hash[y].bz==calc)return;
	 if (hash[y].bz==calc){
	 	hash[y].next=++L;
	 	hash[y=L].next=0;
	 }
	 hash[y].v=v,hash[y].bz=calc;
}
bool get(int v){
	int y=v%MOD;
	while (hash[y].v!=v&&hash[y].bz==calc&&hash[y].next)y=hash[y].next;
	return hash[y].v==v&&hash[y].bz==calc;
}
void build(int len){
	++calc;
	L=MOD;
	for (int i=2;i<=n;i++)
		for (int j=l[i];j+len-1<=r[i];j++)
			ins(get(j,j+len-1));
}
bool check(int len){
	build(len);
	for (int i=1;i+len-1<=r[1];i++)
		if (!get(get(i,i+len-1)))return 1;
	return 0;
}
void update(int l,int len){
	if (ansbz){
		for (int i=0;i<len;i++)
			if (ans[i+1]<s[i+l])return;
			else
				if (ans[i+1]>s[i+l])break;
	}
	ansbz=1;
	for (int i=0;i<len;i++)
		ans[i+1]=s[i+l];
}
int main(){
	freopen("f.in","r",stdin);
	scanf("%d",&T);
	help[0]=1;
	for (int i=1;i<N;i++)help[i]=(long long)help[i-1]*27%mod;
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf(" %s",s1);
			int len=strlen(s1);
			l[i]=r[i-1]+1;
			for (int j=0;j<len;j++)
				s[l[i]+j]=s1[j];
			r[i]=l[i]+len-1;
		}
		for (int i=1;i<=r[n];i++)
			f[i]=((long long)f[i-1]*27+s[i]-'a'+1)%mod;
		
		int L=1,R=r[1],S=r[1]+1,mid;
		while (L<=R){
			if (check(mid=(L+R)/2))R=mid-1,S=min(S,mid);
			else
				L=mid+1;
		}
		if (S==r[1]+1){
			printf("Impossible\n");	
		}else{
			build(S);
			ansbz=0;
			for (int i=1;i+S-1<=r[1];i++)
				if (!get(get(i,i+S-1)))update(i,S);
			for (int i=1;i<=S;i++)printf("%c",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
