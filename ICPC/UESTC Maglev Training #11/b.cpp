#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ld long double
using namespace std;
const ld pi=acos(-1);
int l,w,R;
ld a,b;
ld sqr(ld x){
	return x*x;
}
int main(){
	scanf("%d %d %d",&R,&l,&w);
	int T;
	scanf("%d",&T);
	while (T--){
		cin>>a>>b;
		ld r=min((ld)R,(ld)l/2);
		if (a<pi/2)r=min(r,sin(a)*l/2);
		if (b<pi/2){
			ld len=sqrt(sqr(l)+sqr(w)-2*l*w*cos(pi/2-b));
			r=min(r,len/2);
			if (a<b){
				ld angle=pi/2+a-asin(sin(pi/2-b)/len*l);
				r=min(r,len*sin(angle)/2);
			}
			if (sqr(len)+sqr(l)-sqr(w)<0)
				r=min(r,w*cos(b)/2);
		}else r=min(r,(w-l*cos(b-pi/2))/2);
		printf("%.7f\n",(double)r);
	}
	return 0;
}
