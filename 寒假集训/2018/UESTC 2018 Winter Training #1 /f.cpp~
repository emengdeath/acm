#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
#include<cstring>
#define MOD 100000000
using namespace std;
struct node{
	int x[20];
	void clear(){
		for (int i=0;i<20;i++)x[i]=0;
	}
}f[N][10][2],ans;
char s[N];
int T,n;
node operator+(node&a,node&b){
	node s;
	s.clear();
	s.x[0]=max(a.x[0],b.x[0]);
	for (int i=1;i<=s.x[0];i++)
		s.x[i]+=a.x[i]+b.x[i],s.x[i+1]+=s.x[i]/MOD,s.x[i]%=MOD;
	if (s.x[s.x[0]+1])s.x[0]++;
	return s;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s", s+1);
		n=strlen(s+1);
		bool p=0;
		for (int i=2;i<=n;i++)
			if (s[i]<s[i-1]){
				p=1;
				break;
			}
		if (p){
			printf("-1\n");
			continue;
		}
		memset(f,0,sizeof(f));
		ans.clear();
		f[0][0][1].x[0]=f[0][0][1].x[1]=1;
		for (int i=1;i<=n;i++){
			s[i]-='0';
			for (int j=0;j<10;j++)
				for (int k=0;k<=1;k++)
					if (f[i-1][j][k].x[0])
					for (int l=j;l<=10;l++){
						if (l>s[i]&&k)break;
						f[i][l][l==s[i]&&k]=f[i][l][l==s[i]&&k]+f[i-1][j][k];
					}
			f[i][0][0].clear();
			f[i][0][0].x[0]=f[i][0][0].x[1]=1;
		}
		for (int i=0;i<10;i++)
			ans=ans+f[n][i][0];
		int x=ans.x[0];
		printf("%d",ans.x[x]);
		while (--x){
			int y=MOD/10;
			while (y)printf("%d",ans.x[x]/y%10),y/=10;
		}
		printf("\n");
	}
	return 0;
}
