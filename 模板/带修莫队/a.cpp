#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
#define S 2154
using namespace std;
struct node{
	int l,r,t,id;
}b[N];
struct node1{
	int p,x,t,last;
}c[N];
int a[N],d[N],ans[N],sum[N],list[N],e[N*2];
int n,m,totb,totc;
//key!!!!!!!!!!!!!!!!!!!
bool cmp1(const node&a,const node&b){
	return a.l/S<b.l/S||(a.l/S==b.l/S&&(a.r/S<b.r/S||(a.r/S==b.r/S&&a.t<b.t)));
}
int er(int x){
	int l=1,r=e[0],mid;
	while (l<=r){
		if (e[mid=(l+r)/2]==x)return mid;
		else
		if (e[mid]>x)r=mid-1;
		else
			l=mid+1;
	}
	if (e[l]==x)return l;
	if (e[r]==x)return r;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),e[i]=d[i]=a[i];
	e[0]=n;
	for (int i=1;i<=m;i++){
		int sig,x,y;
		scanf("%d %d %d",&sig,&x,&y);
		if (sig==1)b[++totb].l=x,b[totb].r=y,b[totb].t=i,b[totb].id=totb;
		else
			c[++totc].p=x,c[totc].x=y,c[totc].t=i,c[totc].last=d[x],d[x]=y,e[++e[0]]=y;
	}
	sort(e+1,e+e[0]+1);
	int x=e[0];
	e[0]=1;
	for (int i=2;i<=x;i++)
		if (e[e[0]]!=e[i])e[++e[0]]=e[i];
	for (int i=1;i<=n;i++)a[i]=er(a[i]);
	for (int i=1;i<=totc;i++)c[i].x=er(c[i].x),c[i].last=er(c[i].last);
	sort(b+1,b+totb+1,cmp1);
	int l=1,r=0,ll=0;
	for (int i=1;i<=totb;i++){
		while (c[ll].t>b[i].t){
			if (l<=c[ll].p&&c[ll].p<=r){
				list[sum[c[ll].x]]--;
				sum[c[ll].x]--;
				list[sum[c[ll].x]]++;
				list[sum[c[ll].last]]--;
				sum[c[ll].last]++;
				list[sum[c[ll].last]]++;
			}
			a[c[ll].p]=c[ll].last;
			ll--;
		}
		while (ll<totc&&c[ll+1].t<b[i].t){
			ll++;
			if (l<=c[ll].p&&c[ll].p<=r){
				list[sum[c[ll].x]]--;
				sum[c[ll].x]++;
				list[sum[c[ll].x]]++;
				list[sum[c[ll].last]]--;
				sum[c[ll].last]--;
				list[sum[c[ll].last]]++;
			}
			a[c[ll].p]=c[ll].x;
		}
		if (l/S!=b[i].l/S){
			if (i){
				for (int j=b[i-1].l;j<=b[i-1].r;j++)sum[a[j]]=0;
				for (int j=1;j<=S;j++)list[j]=0;	
			}
			l=b[i].l;
			r=l-1;
		}
		while (l<b[i].l){
			list[sum[a[l]]]--;
			sum[a[l]]--;
			list[sum[a[l]]]++;
			l++;
		}
		while (l>b[i].l){
			list[sum[a[l-1]]]--;
			sum[a[l-1]]++;
			list[sum[a[l-1]]]++;
			l--;
		}
		while (r<b[i].r){
			list[sum[a[r+1]]]--;
			sum[a[r+1]]++;
			list[sum[a[r+1]]]++;
			r++;
		}
		while (r>b[i].r){
			list[sum[a[r]]]--;
			sum[a[r]]--;
			list[sum[a[r]]]++;
			r--;
		}
		for (int j=1;;j++)
			if (!list[j]){
				ans[b[i].id]=j;
				break;	
			}
	}
	for (int i=1;i<=totb;i++)printf("%d\n",ans[i]);
	return 0;
}
