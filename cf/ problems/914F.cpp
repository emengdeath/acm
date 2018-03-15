#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100001
#define S 100
#define S2 1000
#define MOD 1000000007
#define MOD1 1999997
#include<cstring>
using namespace std;
struct node{
	int sig,l,r,len;
	long long v;
}q[N];
struct node1{
	long long v;
	int len;
	int bz;
}hash[MOD1*2];
long long help[N];
int sum[N][S];
char s[N],s1[N];
int L0,tot,n,m;
void ins1(long long v,int len){
	int y=(v*N+len)%MOD1;
	if (hash[y].bz)return;
	hash[y].v=v,hash[y].len=len,hash[y].bz=++tot;
}
int get(long long v,int len){
	int y=(v*N+len)%MOD1;
	return hash[y].bz-1;
}
void build(int l,int r,int bz){
	int sig=l/S2;
	for (int i=l;i<=r;i++){
		long long v=0;
		for (int j=i;j<=r;j++){
			v=(v*27+s[j])%MOD;
			int z=get(v,j-i+1);
			if (z>=0)sum[z][sig]+=bz;	
			if (j-i+1==S)break;
		}
	}
}
void build1(int l,int r,int ll,int bz){
	int sig=l/S2;
	for (int i=max(l,ll-S+1);i<=ll;i++)
		if (i+S-1>=ll){
			long long v=0;
			for (int j=i;j-i+1<=S;j++){
				v=(v*27+s[j])%MOD;
				if (j>=ll){
					int z=get(v,j-i+1);
					if (z>=0)sum[z][sig]+=bz;	
				}
			}
		}
}
int main(){
	//freopen("914F.in","r",stdin);
	L0=MOD1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)s[i]+=1-'a';
	help[0]=1;
	for (int i=1;i<=n;i++)help[i]=help[i-1]*27%MOD;
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&q[i].sig);
		if (q[i].sig==1){
			scanf("%d",&q[i].l);
			char c;
			scanf(" %c",&c);
			q[i].v=c-'a'+1;		
		}else{
			scanf("%d %d",&q[i].l,&q[i].r);
			scanf("%s",s1);
			q[i].len=strlen(s1);
			for (int j=0;j<q[i].len;j++)
				q[i].v=(q[i].v*27+s1[j]-'a'+1)%MOD;
			if (q[i].len<=S)
				ins1(q[i].v,q[i].len);
		}
	}
	for (int i=1;i<=n;i+=S2)
		build(i,min(i+S2-1,n),1);
	for (int i=1;i<=m;i++){
		if (q[i].sig==1){
			int j=1;
			while (j+S2<=q[i].l)j+=S2;
			build1(j,min(j+S2-1,n),q[i].l,-1);
			s[q[i].l]=q[i].v;
			build1(j,min(j+S2-1,n),q[i].l,1);
		}else
		if (q[i].len>S){
			int ans=0;
			long long v=0;
			for (int j=1;j<=q[i].r;j++){
				v=(v*27+s[j])%MOD;
				if (j>q[i].len)v=(v+(MOD-s[j-q[i].len]*help[q[i].len]%MOD))%MOD;
				if (j>=q[i].len&&v==q[i].v&&q[i].l<=j-q[i].len+1)ans++;
			}
			printf("%d\n",ans);
		}else{
			int ans=0;
			int z=get(q[i].v,q[i].len);
			for (int j=1;j<=n;j+=S2){
				int l=j,r=min(j+S2-1,n);
				if (q[i].l<=l&&r<=q[i].r)ans+=sum[z][j/S2];
				else{
					int ll=max(q[i].l,l),rr=min(q[i].r,r);
					long long v=0;
					for (int k=ll;k<=rr;k++){
						v=(v*27+s[k])%MOD;
						if (k-ll+1>q[i].len)v=(v+(MOD-s[k-q[i].len]*help[q[i].len]%MOD))%MOD;
						if (k-ll+1>=q[i].len&&v==q[i].v)ans++;
					}
				}
				if (r<q[i].r){
					int ll=max(q[i].l,r-q[i].len+1),rr=min(min(n,ll+q[i].len-1),q[i].r);
					if (rr-ll+1<q[i].len)continue;
					long long v=0;
					for (int k=ll;k<=rr;k++)
						v=(v*27+s[k])%MOD;
					if (rr>r&&v==q[i].v)ans++;
					for (int k=rr+1;k<=n&&k-q[i].len+1<=r&&k<=q[i].r;k++){
						v=(v*27+s[k]+(MOD-s[k-q[i].len]*help[q[i].len]%MOD))%MOD;
						if (v==q[i].v)ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
