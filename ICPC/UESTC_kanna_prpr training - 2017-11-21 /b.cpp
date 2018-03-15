#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 10000
#include<cstring>
using namespace std;
bool b[N][2];
char s[N];
int n;
int main(){
	freopen("boolean.in","r",stdin);
	freopen("boolean.out","w",stdout);
	scanf(" %s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if ('a'<=s[i]&&s[i]<='z')
			b[s[i]-'a'][s[i-1]=='~']=1;
		else
		if ('A'<=s[i]&&s[i]<='Z')
			b[s[i]-'A'+26][s[i-1]=='~']=1;
	int sum=0;
	bool sig=0;
	long long ans=1;
	for (int i=0;i<52;i++){
		sum+=(b[i][0]||b[i][1]);
		sig|=(b[i][0]&&b[i][1]);
	}
	while (sum--)ans*=2;
	sig?printf("%lld",ans):printf("%lld",ans-1);
	return 0;
}
