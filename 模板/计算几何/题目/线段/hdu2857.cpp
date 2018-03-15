#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	void read(){
		scanf("%lf %lf",&x,&y);
	}
};
struct line{
	point s,t;
	void read(){
		s.read(),t.read();
	}
	bool on(point p){
		if (s.x==t.x)
			return min(s.y,t.y)<p.y&&max(s.y,t.y)>p.y;
		return min(s.x,t.x)<p.x&&max(s.x,t.x)>p.x;
	}
}a,b;
int T;
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
double multi(point a,point b,point c){
	return (b-a)*(c-a);
}
bool Across(line a,line b){
	return (long long)multi(a.s,a.t,b.s)*multi(a.s,a.t,b.t)<=0&&(long long)multi(b.s,b.t,a.s)*multi(b.s,b.t,a.t)<=0;
}
double area(point a,point b,point c){
	return fabs(multi(a,b,c));
}
double sqr(double x){
	return x*x;
}
point intersection(line a,line b){
	return ((a.s-a.t)*(b.s*b.t)-(b.s-b.t)*(a.s*a.t))/((b.s-b.t)*(a.s-a.t));
}
point symmetry_point(point a,line l){
	double A=l.t.y-l.s.y,B=l.s.x-l.t.x,C=(l.s.y-l.t.y)*l.s.x+(l.t.x-l.s.x)*l.s.y;
	return point((sqr(B)-sqr(A))*a.x-2*A*B*a.y-2*A*C,(sqr(A)-sqr(B))*a.y-2*A*B*a.x-2*B*C)/(sqr(A)+sqr(B));
}
int main(){
	scanf("%d",&T);
	while (T--){
		a.s.read();
		a.t.read();
		b.s.read();
		b.t.read();
		b.t=symmetry_point(b.t,a);
		point p=intersection(a,b);
		if (p.x==0)p.x=0;
		if (p.y==0)p.y=0;
		printf("%.3f %.3f\n",p.x,p.y);
	}
	return 0;
}
