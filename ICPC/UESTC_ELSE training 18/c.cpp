#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 1000000
using namespace std;
int T,n,ans;
int c[N],bz[N];
int main(){
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		ans=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)bz[c[j]]=0;
			int r=i;
			bz[c[r]]=r;
			while (r<n&&!bz[c[r+1]])++r,bz[c[r]]=r;
			int rr=r;
			ans=max(ans,r-i+1);
			for (int j=r+1;j<=n;j++){
				r=rr;
				if (r-i+1+n-j+1<=ans)break;
				int K=n;
				for (int k=j;k<=n;k++){
					if (bz[c[k]]>=j){
						K=k;
						break;
					}
					if (bz[c[k]])r=min(r,bz[c[k]]-1);
					bz[c[k]]=k;
					ans=max(ans,r-i+1+k-j+1);
				}
				for (int k=j;k<=K;k++)bz[c[k]]=0;
				for (int k=i;k<=rr;k++)bz[c[k]]=k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
