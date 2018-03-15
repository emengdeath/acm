#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 100000000
#define N 2000100
#define M 3011
using namespace std;
int c[M],b[N],d[N];
bool can[M];
int n,k,T,flow,sum,t;
int g[M],a[M*M][3],vh[M],dis[M],di[M],pre[M],his[M];
void ins(int x,int y,int z){
    a[++sum][0]=y,a[sum][1]=z,a[sum][2]=g[x],g[x]=sum;
    a[++sum][0]=x,a[sum][1]=0,a[sum][2]=g[y],g[y]=sum;
}
void clear(int t){
    for (int i=0;i<=t;i++)
        vh[i]=dis[i]=0;
}
void sap(int s,int t){
    static int x,argue,mn,k;
    static bool p;
    clear(t);
    argue=MAXN,x=s;
    vh[0]=t+1;
    while (dis[s]<=t+1){
        p=0;
        his[x]=argue;
        for (int i=di[x];i;i=a[i][2])
            if (a[i][1]&&dis[x]==dis[a[i][0]]+1){
                p=1,argue=min(argue,a[i][1]),di[x]=i,pre[a[i][0]]=x;
                x=a[i][0];
                if (x==t){
                    flow+=argue;
                    while (x!=s){
                        x=pre[x];
                        a[di[x]][1]-=argue;
                        a[di[x]^1][1]+=argue;
                    }
                    argue=MAXN;
                }
                break;
            }
        if (!p){
            if (!(--vh[dis[x]]))break;
            mn=t+2;
            for (int i=g[x];i;i=a[i][2])
                if (a[i][1]&&dis[a[i][0]]<mn)
                    mn=dis[a[i][0]],k=i;
            ++vh[dis[x]=++mn];
            di[x]=k;
            if (x!=s)
                x=pre[x],argue=his[x];
        }
    }
}
int main(){
	freopen("f.in","r",stdin);
	scanf("%d",&T);
	for (int i=2;i<N;i++){
		if (!b[i])
			d[b[i]=++d[0]]=i;
		for (int j=1;j<=b[i];j++)
			if ((long long)d[j]*i>=N)break;
			else
				b[d[j]*i]=j;
	}
	while (T--){
		scanf("%d %d",&n,&k);
		sum=1,flow=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&c[i]),can[i]=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (d[b[c[i]+c[j]]]==c[i]+c[j])
					can[i]=can[j]=1;
		int tot=0;
		for (int i=1;i<=n;i++)
			if (can[i])c[++tot]=c[i];
		n=tot;
		t=n+1;
		for (int i=0;i<=t;i++)g[i]=0;
		for (int i=1;i<=n;i++)
			if (c[i]&1){
				ins(0,i,1);
				if (c[i]!=1)
					for (int j=1;j<=n;j++)
						if (!(c[j]&1)&&d[b[c[j]+c[i]]]==c[j]+c[i])
							ins(i,j,1);
			}else
				ins(i,t,1);
		sap(0,t);
		for (int i=1;i<=n;i++)
			if (c[i]==1)
				for (int j=1;j<=n;j++)
					if (!(c[j]&1)&&d[b[c[j]+c[i]]]==c[j]+c[i])
						ins(i,j,1);
		
		sap(0,t);
		int u=0;
		for (int i=g[0];i;i=a[i][2])
			if (c[a[i][0]]==1&&a[i][1])
				u++;
		flow+=(u/2);
		if (flow>=k){
			printf("%d\n",k*2);
			continue;
		}
		printf("%d\n",flow*2+min(n-flow*2,k-flow));
	}
	return 0;
}
