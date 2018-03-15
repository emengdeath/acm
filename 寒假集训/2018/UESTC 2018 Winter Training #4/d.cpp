#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000001
using namespace std;
int f[N];
int a[N];
int T,n,sum1,sum2;
int main(){
	freopen("cases.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++)f[a[j]]=0;
			sum1=sum2=0;
			for (int j=i;j<=n;j++){
				f[a[j]]++;
				if (f[a[j]]==1)sum1++;
				else
				if (f[a[j]]&1)sum1++,sum2--;
				else
					sum1--,sum2++;
				if (sum1==1)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
