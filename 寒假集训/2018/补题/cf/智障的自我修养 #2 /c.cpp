#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2000
#include<cmath>
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){
		x=X,y=Y;
	}
}d[20],e[3][20];
struct circle{
	point p;
	double r;
}a[3];
int tot,ans,ans1,tot1[3];
point operator/(point a,double b){
	return point(a.x/b,a.y/b);
}
point operator*(point a,double b){
	return point(a.x*b,a.y*b);
}
point operator+(point a,point b){
	return point(a.x+b.x,a.y+b.y);
}
point operator-(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
point rotate(point a,double w){
	return point(cos(w)*a.x-sin(w)*a.y,sin(w)*a.x+cos(w)*a.y);
}
double sqr(double x){
	return x*x;
}
double dis(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void work(circle a,circle b,int x,int y){
	double len=dis(a.p,b.p);
	if (len<=a.r+b.r&&!(max(a.r,b.r)-min(a.r,b.r)>len)){
		double w=acos((sqr(len)+sqr(a.r)-sqr(b.r))/(2*len*a.r));
		point c=b.p-a.p;
		d[++tot]=rotate(c/len*a.r,w)+a.p;
		d[++tot]=rotate(c/len*a.r,-w)+a.p;
		e[x][++tot1[x]]=d[tot-1];
		e[x][++tot1[x]]=d[tot];
		e[y][++tot1[y]]=d[tot-1];
		e[y][++tot1[y]]=d[tot];
	}
}
bool cmp(const point&a,const point&b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool nojiao(circle a,circle b){
	return dis(a.p,b.p)>a.r+b.r||(max(a.r,b.r)-min(a.r,b.r)>dis(a.p,b.p));
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%lf %lf %lf",&a[i].p.x,&a[i].p.y,&a[i].r);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			work(a[i],a[j],i,j);
	sort(d+1,d+tot+1,cmp);
	if (tot)ans=-1;
	else
		ans=0;
	for (int i=2;i<=tot;i++)
		if (abs(d[i].x-d[i-1].x)>1e-5||abs(d[i].y-d[i-1].y)>1e-5)ans--;
	for (int i=0;i<3;i++){
		if (!tot1[i])continue;
		sort(e[i]+1,e[i]+tot1[i]+1,cmp);
		ans++;
		for (int j=2;j<=tot1[i];j++)
			if (abs(e[i][j].x-e[i][j-1].x)>1e-5||abs(e[i][j].y-e[i][j-1].y)>1e-5)ans++;
	}
	if (n==1)ans1=1;
	else
	if (n==2){
		if (ans==0)ans1=2;
	}else{
		if (nojiao(a[0],a[1])&&nojiao(a[0],a[2]))ans1++;
		if (nojiao(a[0],a[1])&&nojiao(a[1],a[2]))ans1++;
		if (nojiao(a[0],a[2])&&nojiao(a[1],a[2]))ans1++;
	}
	if (ans1==n)ans=1;
	else
		ans+=2;
	printf("%d\n",ans+ans1);
	return 0;
}
