#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
int C[N+1][N+1];
int main(){
	C[0][0]=1;
	for (int i=1;i<=N;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for (int i=1;i<=N;i++){
		int ans=0;
		for (int j=1;j<=i;j++)
			if (C[i][j]%9==0)ans++;
		printf("%d,",ans);
	}
	return 0;
}
