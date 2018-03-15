#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int p,ans;
int a[8],c[8],num[8],sum50,sum500;
int b[8]={1,5,10,20,100,200,1000,2000};
void update(int s){
	if (s>-1){
		if (ans==-1||ans<s)ans=s;
	}
}
bool check(int x,int p){
	while (x>=0){
		int sum=min(p/b[x],c[x]);
		p-=sum*b[x];
		x--;
	}
	return !p;
}
void put(int x,int p){
	while (x>=0){
		int sum=min(p/b[x],c[x]);
		p-=sum*b[x];
		num[x]+=sum;
		c[x]-=sum;
		x--;
	}
}
int dfs(int p,int s){
	if (p<0)return -1;
	if (!p)return s;	
	for (int i=0;i<8;i++)c[i]=a[i],num[i]=0;
	c[4]+=sum50/2;
	c[6]+=sum500/2;
	for (int i=7;i>=0;i--){
		int sum=min(p/b[i],c[i]);
		c[i]-=sum;
		num[i]=sum;
		p-=b[i]*sum;
	}
	if (p)return -1;
	for (int i=7;i>0;i--){
		int l=0,r=num[i],mid,s=0;
		while (l<=r){
			if (check(i-1,(mid=(l+r)/2)*b[i]))s=max(s,mid),l=mid+1;
			else
				r=mid-1;
		}
		num[i]-=s;
		put(i-1,s*b[i]);
	}
	for (int i=0;i<8;i++)s+=num[i];
	s+=min(sum50/2,num[4])+min(sum500/2,num[6]);
	return s;	
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&p);
		for (int i=0;i<4;i++)
			scanf("%d",&a[i]);
		scanf("%d",&sum50);
		for (int i=4;i<6;i++)
			scanf("%d",&a[i]);
		scanf("%d",&sum500);
		for (int i=6;i<8;i++)
			scanf("%d",&a[i]);
		ans=-1;
		update(dfs(p,0));
		if (sum50){
			sum50--;
			update(dfs(p-50,1));
			sum50++;
		}
		if (sum500){
			sum500--;
			update(dfs(p-500,1));
			sum500++;
		}
		if (sum50&&sum500){
			sum500--,sum50--;
			update(dfs(p-550,2));
		}
		printf("%d\n",ans);
	}
	return 0;
}
