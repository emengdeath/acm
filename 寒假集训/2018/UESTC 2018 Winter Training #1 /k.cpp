#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
#include<cstring>
#include<cmath>
using namespace std;
struct node{
	int x,y,z;
	void read(){
		scanf("%d %d %d",&x,&y,&z);
	}
}a[N];
double f[N][N];
struct name{
	char name[60];
}b[N],A,B;
int n;
bool operator!=(name&a,name&b){
	int len=strlen(a.name);
	int len1=strlen(b.name);
	if (len!=len1)return 1;
	for (int i=0;i<len;i++)
		if (a.name[i]!=b.name[i])return 1;
	return 0;
}
long long sqr(long long x){
	return x*x;
}
double dis(node&a,node&b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}
int getid(name&a){
	int x=1;
	while (a!=b[x])x++;
	return x;
}
int main(){
	int T;
	scanf("%d",&T);
	int sig=0;
	while (T--){
		printf("Case %d:\n",++sig);
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s",b[i].name);
			a[i].read();
		}
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=dis(a[i],a[j]);
		int m;
		scanf("%d",&m);
		while (m--){
			scanf("%s %s",A.name,B.name);
			int x=getid(A),y=getid(B);
			f[x][y]=0;
		}	
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j)
					for (int k=1;k<=n;k++)
						if (i!=k&&j!=k)
							f[k][j]=min(f[k][i]+f[i][j],f[k][j]),f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
		scanf("%d",&m);
		while (m--){
			scanf("%s %s",A.name,B.name);
			int x=getid(A),y=getid(B);
			printf("The distance from %s to %s is %.0f parsecs.\n",A.name,B.name,f[x][y]);
		}
	}
	return 0;
}
