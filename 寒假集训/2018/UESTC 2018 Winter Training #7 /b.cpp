#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100
#define MOD 1000000007
#include<cstring>
using namespace std;
int a[N],b[N];
long long C[N][N];
char s[N];
int n;
long long calc(){
	long long s=1;
	int all=0;
	for (int i=0;i<13;i++)
		all+=b[i];
	for (int i=0;i<13;i++)
		(s*=C[all][b[i]])%=MOD,all-=b[i];
	return s;
}
int main(){
	freopen("b.in","r",stdin);
	C[0][0]=1;
	for (int i=1;i<N;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	while (scanf(" %s",s+1)!=EOF){
		n=strlen(s+1);
		a[0]=0;
		for (int i=0;i<13;i++)b[i]=4;
		for (int i=1;i<=n;i++)
			if (s[i]=='A')a[++a[0]]=0;	
			else
			if ('2'<=s[i]&&s[i]<='9')a[++a[0]]=s[i]-'1';
			else
			if (s[i]=='1')a[++a[0]]=9,i++;
			else
			if (s[i]=='J')a[++a[0]]=10;
			else
			if (s[i]=='Q')a[++a[0]]=11;
			else
				a[++a[0]]=12;
		for (int i=1;i<=a[0];i++)
			b[a[i]]--;
		long long ans=calc();
		bool sig1=0;
		for (int i=1;i<=a[0];i++){
			for (int j=0;j<13;j++)
				if (b[j]&&j>a[i]){
					b[j]--;
					long long v=calc();
					(ans+=MOD-v)%=MOD;
					b[j]++;
				}
			b[a[i]]--;
			if (b[a[i]]<0){
				sig1=1;
				break;
			}
		}
		if (!sig1&&a[0]<=52-a[0])
			(ans+=MOD-calc())%=MOD;
		printf("%lld\n",ans);	
	}	
	return 0;
}
