#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100
#define M 100000
using namespace std;
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	void read(){
		scanf("%lf %lf",&x,&y);
	}
}a[3];
int b[8][2]={{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
int dis[N][N],d[M+1][2];
char map[N][N];
int n;
point operator-(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
point operator+(point a,point b){
	return point(a.x+b.x,a.y+b.y);
}
point operator/(point a,double b){
	return point(a.x/b,a.y/b);
}
double operator*(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double cross(point a,point b,point c){
	return (b-a)*(c-a);
}
bool in(point u){
	return cross(a[0],a[1],u)>0&&cross(a[1],a[2],u)>0&&cross(a[2],a[0],u)>0;
}
bool jiao(point A,point b,point c,point d){
	if (!cross(a[0],a[1],a[2]))return 0;
	return cross(A,b,c)*cross(A,b,d)<0&&cross(c,d,A)*cross(c,d,b)<0;
}
bool check(point u,point v){
	if (u.x<0||u.y<0||u.x==n||u.y==n)return 0;
	if (map[(int)u.x][(int)u.y]=='#')return 0;
	return !in(u)&&!in(v)&&!in((u+v)/2)&&!jiao(u,v,a[0],a[1])&&!jiao(u,v,a[1],a[2])&&!jiao(u,v,a[2],a[0]);
}
void spfa(){
	int l=0,r=1;
	d[1][0]=d[1][1]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)dis[i][j]=0;
	if (map[0][0]=='#')return;
	dis[0][0]=1;
	while (l!=r){
		l=l%M+1;
		int len=dis[d[l][0]][d[l][1]]+1;
		for (int i=0;i<8;i++){
			int x=d[l][0]+b[i][0],y=d[l][1]+b[i][1];
			if (check(point(x,y),point(d[l][0],d[l][1]))){
				if (!dis[x][y]){
					dis[x][y]=len;
					d[r=r%M+1][0]=x,d[r][1]=y;
				}			
			}
		}
	}
}
int main(){
	freopen("g.in","r",stdin);
	while (scanf("%d",&n)!=EOF){
		a[0].read(),a[1].read(),a[2].read();
		if (cross(a[0],a[1],a[2])<0){
			swap(a[1],a[2]);
		}
		for (int j=n-1;j>=0;j--)
			for (int i=0;i<n;i++)
				scanf(" %c",&map[i][j]);
		spfa();
		printf("%d\n",dis[n-1][n-1]-1);
	}
	return 0;
}
