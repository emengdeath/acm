#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int T,n;
double f[N];
int main(){
	for (int i=2;i<N;i++)f[i]=(f[i-1]+(f[i-1]+1)*f[i-1]+(f[i-1]+2)/(i-f[i-1]-1))/i;
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		scanf("%d",&n);
		printf("Case #%d: %.8f\n",sig,f[n]);
	}
	return 0;
}
