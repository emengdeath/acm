#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000001
#define eps 1e-5
#include<cmath>
using namespace std;
double l,r,len;
int n;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
}a[N];
point operator-(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
double operator*(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double cross(point a,point b,point c){
	return (b-a)*(c-a);
}
double calc(double x){
	double y=0;
	for (int i=1;i<=n;i++)
		if (cross(point(x,0),point(0,y),a[i])<-eps){
			y=a[i].y/(x-a[i].x)*x;
		}
	return sqrt(y*y+x*x);
}
int main(){
	while (scanf("%d",&n)!=EOF){
		l=0,r=1000000;
		for (int i=1;i<=n;i++)scanf("%lf %lf",&a[i].x,&a[i].y),l=max(l,a[i].x);
		while (l<=r){
			len=(r-l)/3;
			double v1=calc(l+len);
			double v2=calc(r-len);
			if (v1>=v2)l+=len+eps;
			else
				r-=len+eps;
		}
		printf("%.4f\n",calc(l));
	}
	return 0;
}
