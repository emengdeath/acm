#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000100
#include<cstring>
using namespace std;
int f[2][3][8];
char s[N],b[100];
int n,T,ans;
bool bz,bz1;
bool check(int x){
	return x==2;
}
void update(int z){
	for (int i=0;i<3;i++)
		for (int j=0;j<8;j++)
			f[bz1][i][j]=f[bz][i][j];
	for (int i=0;i<2;i++)
		for (int j=0;j<8;j++)
		if (f[bz][i][j]){
			f[bz1][i+1][(j*2+0)%8]=max(f[bz1][i+1][(j*2+0)%8],f[bz][i][j]+(check(j*2+0)&&z+i+1>=4));
			f[bz1][i+1][(j*2+1)%8]=max(f[bz1][i+1][(j*2+1)%8],f[bz][i][j]+(check(j*2+1)&&z+i+1>=4));
		}
	bz^=1,bz1^=1;
}
void update(int x,int z){
	for (int i=0;i<3;i++)
		for (int j=0;j<8;j++)
			f[bz1][i][j]=0;
	for (int i=0;i<3;i++)
		for (int j=0;j<8;j++)
		if (f[bz][i][j]){
			f[bz1][i][(j*2+x)%8]=max(f[bz1][i][(j*2+x)%8],f[bz][i][j]+(check(j*2+x)&&z+i>=4));
		}
	bz^=1,bz1^=1;
}
int main(){
	freopen("e.in","r",stdin);
	scanf("%d",&T);
	bz=0,bz1=1;
	while (T--){
		scanf("%d",&n);
		scanf(" %s",s+1);
		memset(f,0,sizeof(f));
		f[bz][0][0]=1;
		for (int i=1;i<=n;i++){
			update(i-1);
			update(i-1);
			if (s[i]=='C')update(0,i);
			else
				update(1,i);
		}
		update(n);
		update(n);
		ans=0;
		for (int i=0;i<3;i++)
			for (int j=0;j<8;j++)
				ans=max(ans,f[bz][i][j]-i*(i-1)/2);
		printf("%d\n",ans-1);
	}
	return 0;
}
