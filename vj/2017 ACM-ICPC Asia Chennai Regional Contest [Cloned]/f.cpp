#include<bits/stdc++.h>
#define eps 1e-5
using namespace std;
typedef double ld;
ld a,r1,r2,r3;
int tot;
struct node{
	ld l,r;
}d[100];
bool jian(ld a,ld b){
	return abs(a-b)<eps;
}
ld sqr(ld x){
	return x*x;
}
void work(ld x,ld y,ld xx,ld r){
	ld dis=abs(xx-x);
	if (dis>r)return;
	dis=sqrt(sqr(r)-sqr(dis));
	d[++tot].l=y-dis;
	d[tot].r=y+dis;
}
ld f(ld x){
	tot=0;
	if (-a<=x&&x<=a){
		d[++tot].l=0;
		if (x<0)d[tot].r=a*sqrt((ld)3)*(a+x)/a;
		else
			d[tot].r=a*sqrt((ld)3)*(a-x)/a;
	}
	work(0,0,x,r1);
	work(((ld)a)/2,a*sqrt((ld)3)/2,x,r2);
	work(-((ld)a)/2,sqrt((ld)3)*a/2,x,r3);
	if (tot!=4)return 0;
	for (int i=2;i<=tot;i++)
		d[1].l=max(d[1].l,d[i].l),d[1].r=min(d[1].r,d[i].r); 
	return max(d[1].r-d[1].l,(ld)0);	
}/*
ld simpson(ld l,ld r,ld fl,ld fr,ld fmid){
	return (fl+fr+fmid*4)*((r-l)/6);
}
ld area(ld l,ld r,ld mid,ld fl,ld fr,ld fmid,ld s){
	ld midl,midr;
	ld fmidl,fmidr,sl,sr;
	midl=(l+mid)/2,midr=(mid+r)/2;
	fmidl=f(midl),fmidr=f(midr);
	sl=simpson(l,mid,fl,fmidl,fmid),sr=simpson(mid,r,fmid,fmidr,fr);
	return jian(sl+sr,s)?s:area(l,mid,midl,fl,fmid,fmidl,sl)+area(mid,r,midr,fmid,fr,fmidr,sr);
}
ld get(ld l,ld r){
	ld mid;
	ld fl,fr,fmid;
	mid=(l+r)/2;
	fl=f(l),fr=f(r),fmid=f(mid);
	return area(l,r,mid,fl,fr,fmid,simpson(l,r,fl,fr,fmid));
}*/
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--){
		cin>>a>>r1>>r2>>r3;
		ld ans=0;
		for (ld x=-a;x<=a;x+=eps)
			ans+=f(x)*eps;
		cout<<ans<<endl;
	}
	return 0;
}
