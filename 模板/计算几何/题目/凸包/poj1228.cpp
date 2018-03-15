#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define eps 1e-12
#define N 10000
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	void read(){
		scanf("%lf %lf",&x,&y);
	}
}a[N],d[N];
int n;
point operator-(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
point operator+(point a,point b){
	return point(a.x+b.x,a.y+b.y);
}
point operator*(double a,point b){
	return point(b.x*a,b.y*a);
}
point operator*(point b,double a){
	return point(b.x*a,b.y*a);
}
point operator/(point a,double b){
	return point(a.x/b,a.y/b);
}
bool operator==(point a,point b){
	return a.x==b.x&&a.y==b.y;
}
bool operator!=(point a,point b){
	return a.x!=b.x||a.y!=b.y;
}
double operator*(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double multi(point a,point b,point c){
	return (b-a)*(c-a);
}
double area(point a,point b,point c){
	return fabs(multi(a,b,c));
}
bool cmp(const point&a,const point&b){
	if (a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}
int main(){
	freopen("poj1228.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			a[i].read();
		sort(a+1,a+n+1,cmp);
		while (n>1&&a[n]==a[n-1])n--;
		int tot=1;
		d[1]=a[1];
		for (int i=2;i<=n;i++)
		if (a[i]!=a[i-1]){
			while (tot>=2&&multi(d[tot-1],d[tot],a[i])<0)tot--;
			d[++tot]=a[i];
		}
		if (n>1){
			int len=tot;
			d[++tot]=a[n-1];
			for (int i=n-2;i;i--)
			if (a[i]!=a[i+1]){
				while (len!=tot&&multi(d[tot-1],d[tot],a[i])<0)tot--;
				d[++tot]=a[i];
			}
		}
		bool sig=0;
		if (n<6){
			printf("NO\n");
			continue;
		}
		for (int i=1;i+3<=tot;i++)
			if (multi(d[i],d[i+1],d[i+2])&&multi(d[i+1],d[i+2],d[i+3])){
				sig=1;
				printf("NO\n");
				break;
			}
		if (sig)continue;
		printf("YES\n");
	}
	return 0;
}
