#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
int n,sum,ans;
int a[N][2],g[N],from[N],b[N][2];
bool bz[N];
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
bool dfs(int x){
	for (int i=g[x];i;i=a[i][1])
		if (!bz[a[i][0]]){
			bz[a[i][0]]=1;
			if (!from[a[i][0]]||dfs(from[a[i][0]])){
				from[a[i][0]]=x;
				return 1;
			}
		}
	return 0;
}
void work(int x){
	ans=0;
	for (int i=1;i<=n;i++){
		if (i==x) continue;
		for (int j=1;j<=n+n;j++)
			bz[j]=0;
		ans+=dfs(i);
	}
}
int main(){
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;i++){
			char x,y;
			scanf(" %c %c",&x,&y);
			b[i][0]=x,b[i][1]=y;
		}
		if (n==1){
			printf("YES\n");
			continue;
		}
		bool sig=0;
		for (int i=1;i<=n&&!sig;i++)
			for (int j=1;j<=n&&!sig;j++)
				if (i!=j){
					sum=0;
					for (int k=1;k<=n;k++)g[k]=g[k+n]=from[k]=from[k+n]=0;
					for (int k=1;k<=n;k++)
						if (k!=j)
							for (int l=1;l<=n;l++)
								if (l!=i&&k!=l&&(b[k][0]==b[l][0]||b[k][1]==b[l][1]))
									ins(k,l+n);
					work(j);
					if (ans==n-1){
						sig=1;
					}
				}
		sig?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
