#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100
#define T 100
#define K 33
#include<ctime>
#define random(x)(rand()%(x))
using namespace std;
int t,l,r,c,k;
int main(){
	freopen("f.in","w",stdout);
	t=T;
	printf("%d\n",t);
	while (t--){
		l=random(N),r=random(N);
		c=random(N);
		k=random(K);
		if (l>r)swap(l,r);
		printf("%d %d %d %d\n",l,r,c,k);	
	}
	return 0;
}
