#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 10
#include<ctime>
#define random(x)(rand()%x)
using namespace std;
int T;
int main(){
	freopen("poj1269.in","w",stdout);
	printf("5\n");
	for (int i=1;i<=5;i++){
		for (int j=1;j<=8;j++)
		printf("%d ",random(N));
		printf("\n");
	}
	return 0;
}
