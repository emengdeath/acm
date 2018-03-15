#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD1 10000007
#define MOD2 10000009
#define N 1000000
#include<cstring>
using namespace std;
struct node{
	int x,y;
	node(int X=0,int Y=0){x=X,y=Y;}
}f[N],help[N];
struct node1{
	int a[26];
	int sum,fail;
	void clear(){
		for (int i=0;i<26;i++)a[i]=0;
		sum=fail=0;
	}
}tri[N];
char s[N],S[N];
int n,m,calc;
int l[N],r[N];
int d[N];
bool bz[N];
node operator+(node&a,int x){
	return node((a.x*26+x)%MOD1,(a.y*26+x)%MOD2);
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
	return f[r]-f[l-1]*help[r-l+1];
}
bool operator==(node a,node b){
	return a.x==b.x&&a.y==b.y;
}
void build(){
	int l=0,r=1;
	d[1]=0;
	for (int i=0;i<=calc;i++)bz[i]=0;
	while (l!=r){
		l++;
		for (int i=0;i<26;i++)
			if (tri[d[l]].a[i]&&!bz[tri[d[l]].a[i]]){
				bz[d[++r]=tri[d[l]].a[i]]=1;
				int x=tri[d[l]].fail;
				while (!tri[x].a[i]&&x)x=tri[x].fail;
				tri[d[r]].fail=tri[x].a[i];
			}
	}
}
int main(){
	freopen("d.in","r",stdin);
	help[0]=node(1,1);
	for (int i=1;i<N;i++)help[i]=help[i-1]*26;
	while (scanf("%d",&n)!=EOF){
		while (calc)tri[calc--].clear();
		tri[0].clear();
		int all=0;
		calc=0;
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int x=0,y=0;
			int len=strlen(s);
			r[i]=l[i]=r[i-1];
			l[i]++;
			while (x!=len){
				s[x]-='a';
				if (!tri[y].a[s[x]])tri[y].a[s[x]]=++calc;
				y=tri[y].a[s[x]];
				tri[y].sum++;
				f[r[i]+1]=f[r[i]]+s[x];
				r[i]++;
				S[++all]=s[x];
				x++;
			}
		}
		build();
		scanf("%d",&m);
		while (m--){
			int x,y;
			scanf("%d %d",&x,&y);
			int L=0,R=min(r[x]-l[x]+1,r[y]-l[y]+1),mid,s1=0;
			while (L<=R){
				mid=(L+R)/2;
				if (get(r[x]-mid+1,r[x])==get(r[y]-mid+1,r[y]))s1=max(s1,mid),L=mid+1;
				else
					R=mid-1;
			}
			y=0;
			while (s1){
				while (y&&!tri[y].a[S[r[x]-s1+1]])y=tri[y].fail;
				y=tri[y].a[S[r[x]-s1+1]];
				s1--;
			}
			y?printf("%d\n",tri[y].sum):printf("N\n");
		}	
	}
	return 0;
}
