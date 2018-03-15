#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N+1],d[N+1],b[N];
int x,p,k;
int get(int x,int y){
	int s=x;
	while (y<=b[0])s-=get(x/b[y],y+1),y++;
	return s;
}
int main(){
	for (int i=2;i<=N;i++){
		if (!a[i]){
			d[a[i]=++d[0]]=i;
		}
		for (int j=1;j<=a[i];j++)
			if ((long long)d[j]*i>N)break;
			else
				a[d[j]*i]=j;
	}
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d %d",&x,&p,&k);
		int l=1,r=N*10,mid,s=N*10;
		b[0]=0;
		while (p!=1){
			if (b[b[0]]!=d[a[p]])b[++b[0]]=d[a[p]];
			p/=d[a[p]];
		}
		x=get(x,1);
		while (l<=r){
			if (get(mid=(l+r)/2,1)-x>=k)r=mid-1,s=min(s,mid);
			else
				l=mid+1;
		}
		printf("%d\n",s);
	}
	return 0;
}
