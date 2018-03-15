#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
#include<cstring>
using namespace std;
bool bz[10];
char s[N];
int n;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
	for (int i=0;i<10;i++)bz[i]=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	if (n&1){
		for (int i=1;i<n;i++)printf("9");
		printf("\n");
	}else{
		for (int i=1;i<=n;i++){
			bz[s[i]-='0']^=1;
		}
		int x=0;
		for (int i=n;i>=1;i--){
			bz[s[i]]^=1;
			for (int j=s[i]-1;j>=0;j--){
				bz[j]^=1;
				int sum=0;
				for (int k=0;k<10;k++)
					sum+=bz[k];
				if (sum<=n-i){
					x=i;
					s[i]=j;
					break;
				}
				bz[j]^=1;
			}
			if (x)break;
		}
		if (!x||s[1]==0)
			for (int i=1;i<n-1;i++)printf("9");		
		else{
			for (int i=1;i<=x;i++)printf("%d",s[i]);
			int sum=0;
			for (int i=0;i<10;i++)sum+=bz[i];
			for (int i=x+1;i<=n;i++){
				if (sum==n-i+1)break;
				printf("9");
				bz[9]^=1;
				if (bz[9])sum++;
				else
					sum--;
			}
			for (int i=9;i>=0;i--)if (bz[i])printf("%d",i);
		}
		printf("\n");
	}
	}
	return 0;
}
