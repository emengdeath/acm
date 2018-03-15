#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 5001
using namespace std;
unsigned short int from[N][N],f[N][N],now[N][N];
bool bz[N];
int v,n,k;
int a[N];
int main(){
	scanf("%d %d %d",&n,&k,&v);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int x=a[i]%k,y=a[i]/k;
		for (int j=0;j<k;j++)from[i][j]=from[i-1][j],f[i][j]=f[i-1][j],now[i][j]=now[i-1][j];
		if (!now[i][x]||y>f[i][x])f[i][x]=y,from[i][x]=0,now[i][x]=i;
		for (int j=0;j<k;j++)
			if (now[i-1][j]){
				int v=(j+x)%k,u=f[i-1][j]+y+(x+j)/k;
				if (!now[i][v]||f[i][v]<u)
					from[i][v]=i-1,now[i][v]=i,f[i][v]=u;
			}
	}
	if (now[n][v%k]||v%k==0){
		int x=v%k,s=now[n][x],y=n;
		int all=0;
		if (!s)s=1;
		while (now[y][x]){
			bz[now[y][x]]=1;
			all+=a[now[y][x]];
			int yy=from[y][x];
			x=(x+k-a[now[y][x]]%k)%k;
			y=yy;
		}
		if (all<v){
			v-=all;
			for (int i=1;i<=n;i++){
				int x=a[i]%k,y=a[i]/k;
				for (int j=0;j<k;j++)from[i][j]=from[i-1][j],f[i][j]=f[i-1][j],now[i][j]=now[i-1][j];
				if (bz[i])continue;
				if (!now[i][x]||y>f[i][x])f[i][x]=y,from[i][x]=0,now[i][x]=i;
				for (int j=0;j<k;j++)
					if (now[i-1][j]){
						int v=(j+x)%k,u=f[i-1][j]+y+(x+j)/k;
						if (!from[i][v]||f[i][v]<u)
							from[i][v]=i-1,now[i][v]=i,f[i][v]=u;
					}
			}
			int x=v%k,y=n;
			all=0;
			while (now[y][x]){
				bz[now[y][x]]=1;
				all+=a[now[y][x]];
				int yy=from[y][x];
				x=(x+k-a[now[y][x]]%k)%k;
				y=yy;
			}
			if (all<v){
				int x=0;
				for (int i=1;i<=n;i++)
					if (!bz[i])
						x+=a[i];
				if (x/k*k+all<v){
					printf("NO\n");
					return 0;
				}
			}
		}	
		int s1=0;
		printf("YES\n");
		for (int i=1;i<=n;i++)
			if (bz[i]&&i!=s&&a[i]/k+(a[i]%k>0)>0)
				printf("%d %d %d\n",a[i]/k+(a[i]%k>0),i,s);
			else
			if (i!=s&&!bz[i])
				s1=i;
		if (s1){
			for (int i=1;i<=n;i++)
				if (!bz[i]&&i!=s1&&a[i]/k+(a[i]%k>0)>0)
					printf("%d %d %d\n",a[i]/k+(a[i]%k>0),i,s1),a[s1]+=a[i];
			if (a[s1]/k)printf("%d %d %d\n",a[s1]/k,s1,s);
			all+=a[s1]/k*k;
		}
		x=1;
		if (s==1)x=2;
		if (all>v&&(all-v)/k)printf("%d %d %d\n",(all-v)/k,s,x);
	}else
		printf("NO");
	return 0;
}
