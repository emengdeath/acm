#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000002
using namespace std;
long long bz[N][3];
int d[100];
int n;
void work(int x){
	for (int i=2;(long long)i*i<=x;i++)
		if (x%i==0){
			d[++d[0]]=i;
			while (!(x%i))x/=i;
		}
	if (x!=1)d[++d[0]]=x;
}
int main(){
	scanf("%d",&n);
	bz[n][2]=1,bz[n-1][2]=-1;
	for (int i=n;i>=1;i--){
		bz[i][0]+=bz[i+1][0],bz[i][1]+=bz[i+1][1],bz[i][2]+=bz[i+1][2];		
		if (bz[i][0]||bz[i][1]||bz[i][2]){
			d[0]=0;
			work(i);
			if (d[1]==i){
				bz[i][0]++;
				bz[i-1][0]--;
				continue;
			}
			for (int j=1;j<=d[0];j++){
				int l=max(i-d[j],d[j]),r=i-1;
				if (l>r)continue;
				if (bz[i][2])
					bz[l][1]--,bz[r][1]++;
				if (bz[i][1])
					bz[l][0]--,bz[r][0]++;
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (bz[i][0]){
			printf("%d\n",i);
			return 0;
		}
	printf("%d\n",n);
	return 0;	
}
