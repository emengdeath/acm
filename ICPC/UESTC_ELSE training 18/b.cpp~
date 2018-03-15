#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
long long maxn;
bool b[N];
bool sigji,sigou;
int n,T,jin,oun,sumji,sumou;
long long k;
long long a[N];
void check(int x){
	if (x&1){
		if (x*2>1+jin)
			sigji&=(b[x]==b[1+jin-x]);
	}else{
		if (x*2>2+oun)
			sigou&=(b[x]==b[2+oun-x]);
	}
}
long long get(int x){
	long long v=0;
	int jim,oum;
	if (x&1)jim=(x+1)/2,oum=x/2;
	else
		jim=x/2,oum=x/2;
	if (sigji){
		int sum=(max(0,sumji-jim*2)+1)/2+sumou-oum;
		v+=a[sum];
	}
	if (sigou){
		int sum=(max(0,sumou-oum*2)+1)/2+sumji-jim;
		v+=a[sum];
	}
	if (sigou&&sigji){
		int sum=(max(0,sumji-jim*2)+1)/2+(max(0,sumou-oum*2)+1)/2;
		v-=a[sum];
	}
	return v;
}
int main(){
	scanf("%d",&T);
	a[0]=1;
	maxn=(long long)1e9*1e9*4;
	maxn+=1;
	for (int i=1;i<N;i++)a[i]=min(a[i-1]*2,maxn);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d %I64d",&n,&k);
		sigji=sigou=1;
		if (n&1)jin=n,oun=n-1,sumji=(n+1)/2,sumou=n/2;
		else
			jin=n-1,oun=n,sumji=n/2,sumou=n/2;
		for (int i=1;i<=n;i++){
			bool bz1=sigji,bz2=sigou;
			b[i]=0;
			check(i);
			long long v=get(i);
			if (v<k){
				k-=v;
				b[i]=1;
				sigji=bz1,sigou=bz2;
				check(i);
			}else
				b[i]=0;
		}
		if (k==1){
			for (int i=1;i<=n;i++)
				if (b[i])printf("1");else printf("0");
		}else
			printf("NOT FOUND!");
		printf("\n");
	}
	return 0;
}
