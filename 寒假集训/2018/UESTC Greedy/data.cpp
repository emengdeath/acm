#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define N 10
#define sum 10
#define random(x)(rand()%(x))
using namespace std;
int T;
int main(){
	freopen("b.in","w",stdout);
	srand((int)time(0));
	T=N;
	printf("%d\n",T);
	while (T--){
		int n=random(N)+2;
		printf("%d\n",n);
		for (int i=2;i<=n;i++)
			printf("%d %d\n",random(i-1)+1,i);
	}
	return 0;
}
