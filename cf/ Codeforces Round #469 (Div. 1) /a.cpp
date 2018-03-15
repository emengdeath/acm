#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
#include<cstring>
using namespace std;
int d0[N],ans[N],d1[N],l[N],r[N];
char s[N];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=n;i>=1;i--)
		if (s[i]=='0'){
			if (d1[0])r[i]=d1[d1[0]--],l[r[i]]=i;
			d0[++d0[0]]=i;
		}else{
			if (d0[0])r[i]=d0[d0[0]--],l[r[i]]=i;
			d1[++d1[0]]=i;
		}
	int sum=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='1'&&(!l[i]||!r[i])){
			printf("-1\n");
			return 0;
		}else
		if (!l[i]){
			sum++;
		}
	printf("%d\n",sum);
	for (int i=1;i<=n;i++)
		if (!l[i]){
			ans[0]=1,ans[1]=i;
			int j=i;
			while (r[j])ans[++ans[0]]=(j=r[j]);
			printf("%d",ans[0]);
			for (int j=1;j<=ans[0];j++)
				printf(" %d",ans[j]);
			printf("\n");
		}
	return 0;
}
