#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int fa[N];
int n,m,sum,calc;
int g[N],a[N][2],b[N],son[N],num[N],list[N];
int l[N],r[N];
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x){
	son[x]=0;
	l[x]=++calc;
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa[x]){
			fa[a[i][0]]=x;
			son[x]++;
			dfs(a[i][0]);
		}
	r[x]=calc;
}
bool cmp(int x,int y){
	return l[x]<l[y]||(l[x]==l[y]&&r[x]>r[y]);
}
bool inclu(int x,int y){
	return l[x]<=l[y]&&r[x]>=r[y];
}
int main(){
	freopen("f.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		scanf("%d %d",&n,&m);
		sum=0;
		for (int i=1;i<=n;i++)g[i]=0;
		for (int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			ins(x,y),ins(y,x);
		}
		calc=0;
		dfs(1);
		while (m--){
			int y;
			scanf("%d",&y);
			int ans=n-y;
			for (int i=1;i<=y;i++)
				scanf("%d",&b[i]),num[b[i]]=son[b[i]];
			sort(b+1,b+y+1,cmp);
			for (int i=1;i<=y;i++){
				list[++list[0]]=b[i];
				while (list[0]>1&&!inclu(list[list[0]-1],list[list[0]])){
					if (list[0]>2){
						if (!num[list[list[0]-1]]&&fa[list[list[0]-1]]==list[list[0]-2])
							num[list[list[0]-2]]--;
					}
					list[list[0]-1]=list[list[0]];
					list[0]--;
				}
			}
			while (list[0]>1){
				if (!num[list[list[0]]]&&fa[list[list[0]]]==list[list[0]-1])
					num[list[list[0]-1]]--;
				list[0]--;
			}
			for (int i=1;i<=y;i++)
				if (num[b[i]]>1)ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
