#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 500001
using namespace std;
struct node{
	int x,y;
}a[N],b[N];
int n,m;
long long ans;
bool cmp(const node&a,const node&b){
	return a.x<b.x;
}
long long get(node&a,node&b){
	if (a.x>b.x||a.y>b.y)return -abs((a.x-b.x)*(a.y-b.y));
	else
		return abs((a.x-b.x)*(a.y-b.y));
}
int main(){
	while (scanf("%d %d",&n,&m)!=EOF){
		for (int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].y);
		for (int i=1;i<=m;i++)scanf("%d %d",&b[i].x,&b[i].y);
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+m+1,cmp);
		int x=n;
		n=1;
		for (int i=2;i<=x;i++)
			if (a[i].y<a[n].y)a[++n]=a[i];
		x=m;
		m=1;
		for (int i=2;i<=x;i++){
			while (m&&b[m].y<=b[i].y)m--;
			b[++m]=b[i];
		}
		ans=0;
		int r=0,k=1;
		for (int i=1;i<=n;i++){
		//	while (r>1&&abs(get(a[i],b[r]))<abs(get(a[i],b[r-1])))r--;
			while (get(a[i],b[r+1])>0)r++;
			while (k<=r&&get(a[i],b[k])<0)k++;
			for (int j=k+1;j<=r;j++)
				if (get(a[i],b[j])>get(a[i],b[k]))k=j;
			if (k<=r)
				ans=max(get(a[i],b[k]),ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
