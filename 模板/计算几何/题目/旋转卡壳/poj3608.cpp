#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 20000
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	void read(){
		scanf("%lf %lf",&x,&y);
	}
}a[N],b[N];
int n,m;
struct line{
	point s,t;
	line(point S=point(0,0),point T=point(0,0)){
		s=S,t=T;
	}
};
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
double operator*(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double dotcross(point a,point b){
	return a.x*b.x+a.y*b.y;
}
double multi(point a,point b,point c){
	return (b-a)*(c-a);
}
double area(point a,point b,point c){
	return fabs(multi(a,b,c));
}
double sqr(double x){
	return x*x;
}
double dis(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void anticlockwise_sort(point*a,int n){
	for (int i=1;i<=n;i++){
		double tmp=multi(a[i],a[i%n+1],a[(i%n+1)%n+1]);
		if (tmp<0){
			reverse(a+1,a+n+1);
			return;
		}else
		if (tmp>0)return;
	}
}
double point_line_dis(point p,line l){
	return area(p,l.s,l.t)/dis(l.s,l.t);
}
double point_seg_dis(point p,line seg){
	if (dotcross(p-seg.s,seg.t-seg.s)<=0)return dis(seg.s,p);
	if (dotcross(p-seg.t,seg.s-seg.t)<=0)return dis(seg.t,p);
	return point_line_dis(p,seg);
}
double seg_seg_dis(line a,line b){
	return min(point_seg_dis(b.s,a),min(point_seg_dis(b.t,a),min(point_seg_dis(a.s,b),point_seg_dis(a.t,b))));
}
double polygon_dis(point*a,int n,point*b,int m){
	anticlockwise_sort(a,n);
	anticlockwise_sort(b,m);
	int ymin=1,ymax=1;
	for (int i=1;i<=n;i++)if (a[i].y<a[ymin].y)ymin=i;
	for (int i=1;i<=m;i++)if (b[i].y>b[ymax].y)ymax=i;
	double ans=dis(a[1],b[1]);
	for (int i=1;i<=n;i++){
		while (multi(a[ymin%n+1],b[ymax],a[ymin])<multi(a[ymin%n+1],b[ymax%m+1],a[ymin]))ymax=ymax%m+1;
		ans=min(ans,seg_seg_dis(line(a[ymin],a[ymin%n+1]),line(b[ymax],b[ymax%m+1])));
		ymin=ymin%n+1;
	}
	return ans;
}
int main(){
	freopen("poj3608.in","r",stdin);
	while (1){
		scanf("%d %d",&n,&m);
		if (!n&&!m)break;
		for (int i=1;i<=n;i++)a[i].read();
		for (int i=1;i<=m;i++)b[i].read();
		printf("%.5f\n",polygon_dis(a,n,b,m));
	}
	return 0;
}
