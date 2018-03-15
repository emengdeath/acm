#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	void random(){
		x=rand()%1000;
		y=rand()%1000;
	}
}a,b,c;
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
double sqr(double x){
	return x*x;
}
double dis(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point incircle(point a,point b,point c){
	double A=dis(b,c),B=dis(a,c),C=dis(a,b);
	return point((A*a.x+B*b.x+C*c.x)/(A+B+C),(A*a.y+B*b.y+C*c.y)/(A+B+C));	
}
bool isdiff(double x,double y){
	return fabs(x-y)>1e-5;
}
int main(){
	srand((int)time(0));
	while (1){
		a.random();
		b.random();
		c.random();
		point p=incircle(a,b,c);
		double A=area(a,b,p)/dis(a,b),B=area(a,c,p)/dis(a,c),C=area(b,c,p)/dis(b,c);
		if (isdiff(A,B)||isdiff(A,C)||isdiff(B,C)){
			printf("N");
			break;
		}
		printf("Y");
	}
	return 0;
}
