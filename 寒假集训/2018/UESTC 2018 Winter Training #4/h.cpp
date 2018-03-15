#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
char s[N];
int l[N],r[N],llen[N],rlen[N];
int n,T;
int calc(int s,int l,int r){
	if (l){
		if (r){
			return max((r-s)/2,(s-l)/2);
		}else
			return max(n-s,(s-l)/2);
	}else
	if (r){
		return max((r-s)/2,s-1);
	}else
		return n/2;
}
bool check(int len){
	bool sig=0;
	int x=0;
	bool sig1=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='.'){
			if (i-l[i]>len&&r[i]-i>len){
				if (sig&&abs(x-i)<=len)continue;
				if (sig)return 0;
				sig=1;
				x=i+len;
			}
		}else
			if (!sig1){
				if (l[i]<0){
					if (r[i]!=1000000){
						if (r[i]-1<=len){
							sig1=1;
							i=r[i];
						}
					}
				}else
					if (r[i]!=1000000){
						if ((r[i]-l[i])/2<=len){
							sig1=1;
							i=r[i];
						}
					}else
						if (n-l[i]<=len){
							sig1=1;
							i=r[i];
						}
			}
	if (!sig)return 1;
	return sig&&sig1;
}
int main(){
	//freopen("stations.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int x=-1000000;
		for (int i=1;i<=n;i++){
			l[i]=x;
			llen[i]=llen[i-1];
			if (s[i]=='+'){
				if (x<0)llen[i]=max(llen[i],i-1);
				else
					llen[i]=max(llen[i],(i-x)/2);
				x=i;
			}
		}
		x=1000000;
		rlen[n+1]=0;
		for (int i=n;i;i--){
			r[i]=x;
			rlen[i]=rlen[i+1];
			if (s[i]=='+'){
				if (x==1000000)rlen[i]=max(rlen[i],n-i);
				else
					rlen[i]=max(rlen[i],(x-i)/2);
				x=i;
			}
		}
		int L=0,R=n,mid,ss=n;
		int ans=n;
		for (int i=1;i<=n;i++)
			if (s[i]=='+'){
				int L=l[i],R=r[i];
				if (L<0)L=0;
				if (R==1000000)R=0;
				int x=i,v=max(llen[L],rlen[R]);
				while (max(calc(x+1,L,R),v)<max(calc(x,L,R),v)){
					if (R&&x+1>=R)break;
					if (!R&&x+1>=n)break;
					x++;
				}
				while (max(calc(x-1,L,R),v)<max(calc(x,L,R),v)){
					if (L&&x-1<=L)break;
					if (!L&&x-1<1)break;
					x--;
				}
				ans=min(ans,max(calc(x,L,R),v));
			}
		while (L<=R){
			mid=(L+R)/2;
			if (check(mid=(L+R)/2))R=mid-1,ss=min(ss,mid);
			else
				L=mid+1;
		}
		printf("%d\n",min(ans,ss));
	}
	return 0;
}
