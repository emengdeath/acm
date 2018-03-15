#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 10000007
#define N 2000000
#include<cstring>
using namespace std;
int T;
int n,sum;
char s[10];
int f[MOD],ans[N],a[N],b[N];
int turn(char*s){
	int len=strlen(s);
	int v=0;
	for (int i=0;i<len;i++)
		v=(v*27+s[i]-'A'+1)%MOD;
	return v;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			a[i]=turn(s);
		}
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			b[i]=turn(s);
		}
		int l=0;
		ans[0]=0;
		for (int i=1;i<=n;i++){
			f[a[i]]++;
			if (!f[a[i]])sum--;
			else
				if (f[a[i]]==1)sum++;
			f[b[i]]--;
			if (!f[b[i]])sum--;
			else
				if (f[b[i]]==-1)sum++;
			if (!sum){
				ans[++ans[0]]=i-l;
				l=i;
			}
		}
		printf("%d",ans[1]);
		for (int i=2;i<=ans[0];i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
