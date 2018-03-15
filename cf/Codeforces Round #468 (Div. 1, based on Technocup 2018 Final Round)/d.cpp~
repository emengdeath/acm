#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
#define up up23
#define down down23
#define left left23
#define right right23
#include<map>
using namespace std;
struct node{
	int x,y;
}a[N],b[N];
int n,tota,totb,up[3],down[3],left[3],right[3];
bool cmp1(const node&a,const node&b){
	return a.x<b.x;
}
bool cmp2(const node&a,const node&b){
	return a.y<b.y;
}
bool cp(int x,int y){
	return (x&1)==(y&1);
}
long long get(int s){
	long long x=0;
	for (int i=1;i<=s;i++)
		x+=(s-i+1+(i&1))/2;
	return x;
}
int get(node*a,int n){
	if (!n)return 0;
	sort(a+1,a+n+1,cmp1);
	left[0]=a[1].x;
	left[1]=left[2]=a[1].y;
	for (int i=1;i<=n;i++){
		if (a[i].x!=a[1].x)break;
		left[1]=min(left[1],a[i].y);
		left[2]=max(left[2],a[i].y);
	}
	right[0]=a[n].x;
	right[1]=right[2]=a[n].y;
	for (int i=n;i>=1;i--){
		if (a[i].x!=a[n].x)break;
		right[1]=min(right[1],a[i].y);
		right[2]=max(right[2],a[i].y);
	}
	sort(a+1,a+n+1,cmp2);
	down[0]=a[1].y;
	down[1]=down[2]=a[1].x;
	for (int i=1;i<=n;i++){
		if (a[i].y!=a[1].y)break;
		down[1]=min(down[1],a[i].x);
		down[2]=max(down[2],a[i].x);
	}
	up[0]=a[n].y;
	up[1]=up[2]=a[n].x;
	for (int i=n;i>=1;i--){
		if (a[i].y!=a[n].y)break;
		up[1]=min(up[1],a[i].x);
		up[2]=max(up[2],a[i].x);
	}
	long long ans=(long long)(right[0]-left[0]-1)*(up[0]-down[0]-1);
	ans-=get(min(right[0]-up[2]+1,up[0]-right[2]+1)-2);
	ans-=get(min(right[1]-down[0]+1,right[0]-down[2]+1)-2);
	ans-=get(min(down[1]-left[0]+1,left[1]-down[0]+1)-2);
	ans-=get(min(up[0]-left[2]+1,up[1]-left[0]+1)-2);
	return ans;
}
int main(){
	//freopen("d.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if ((x+y)&1)a[++tota].x=x,a[tota].y=y;
		else
			b[++totb].x=x,b[totb].y=y;
	}
	printf("%I64d\n",get(a,tota)+get(b,totb));
	return 0;
}
