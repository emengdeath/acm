#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1000000
using namespace std;
typedef long long LL;
int n,len;
long long m;
int bz[N],bp[N],f[N],d[N],e[N];
long long cp[N];
int A[N];
const LL MOD1=1004535809;
const LL MOD=1000000007;
const LL G=3;
LL wi,invl,u,v;
LL w[N],ap[N],tp[N],a[N];
long long calc(long long x,long long y,long long mod){
	long long z=1;
	while (y){
		if (y&1)(z*=x)%=mod;
		(x*=x)%=mod,y/=2;
	}
	return z;
}
void dft(LL*a,bool sig){
	for (int i=0;i<len;i++)tp[bz[i]]=a[i];
	for (int i=2,stp=len,cur,hal,j,k;i<=len;i<<=1){
		stp>>=1,cur=sig?len:0,hal=i>>1;
		for (j=0;j<hal;j++,sig?cur-=stp:cur+=stp)
			for (k=j,wi=w[cur];k<len;k+=i){
				u=tp[k],v=tp[k+hal]*wi%MOD1;
				tp[k]=(u+v)%MOD1;
				tp[k+hal]=(u-v+MOD1)%MOD1;
			}
	}
	for (int i=0;i<len;i++)a[i]=tp[i];
}
void set(int n){
	for (len=1;len<=n;len<<=1);
	for (int i=0,j,k,l;i<len;bz[k]=i++)
		for (j=i,k=0,l=1;l<len;l<<=1,j>>=1)k=(k<<1)+(j&1);
	invl=calc(len,MOD1-2,MOD1);
	w[0]=1,w[1]=calc(G,(MOD1-1)/len,MOD1);
	for (int i=2;i<=len;i++)w[i]=w[i-1]*w[1]%MOD1;
}
void FFT(LL*ap){
	for (int i=0;i<len;i++)a[i]=ap[i];
	dft(a,0);
	for (int i=0;i<len;i++)a[i]=a[i]*a[i]%MOD1;
	dft(a,1);
	for (int i=0;i<len;i++)(cp[i]=(a[i]*invl)%MOD1)%=MOD;
}
long long sqr(long long s){
	return s*s%MOD;
}
long long ni(long long x){
	return calc(x,MOD-2,MOD);
}
int main(){
	freopen("d.in","r",stdin);
	A[0]=1;
	for (int i=1;i<=100000;i++)A[i]=(long long)A[i-1]*i%MOD;
	int T;
	scanf("%d",&T);
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d: ",sig);
		scanf("%d %lld",&n,&m);
		m--;
		for (int i=0;i<len;i++)bp[i]=f[i]=d[i]=e[i]=ap[i]=0;
		long long all=0;
		int mx=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			mx=max(mx,x);
			all+=x;
			ap[x]++;
			bp[x]++;
			d[x+1]++;
			e[x+x+1]++;
		}
		set(mx*2);
		m-=all*2;
		for (int i=len-1;i>=2;i--)ap[i-1]+=ap[i];
		long long u=0,sum=0;
		for (int i=len-1;i>=0;i--){
			u+=bp[i]*(i+1);
			u-=sum;
			f[i]+=u;
			sum+=bp[i];
		}
		u=0,sum=0;
		for (int i=0;i<len;i++){
			(u+=d[i]*(i-1))%=MOD;
			(u-=sum)%=MOD;
			(f[i]+=u)%=MOD;
			sum+=d[i]-e[i];
		}
		sum=0;
		for (int i=len-1;i;i--)
			sum+=bp[i],f[i]-=sum*2;
		f[0]-=n;
		FFT(ap);
		for (int i=0;i<len;i++)(cp[i]+=MOD-f[i])%=MOD;
		long long ans=0,v=1;
		if (m>0){
			for (int i=1;i<=n;i++)
				(v*=(m+i)%MOD)%=MOD;
			(v*=calc(A[n],MOD-2,MOD))%=MOD;
			(ans+=v*sqr(m)%MOD)%=MOD;
		}
		v=1;
		if (m>0){
			v=1;
			for (int i=1;i<=n-2;i++)
				(v*=(m+i-1)%MOD)%=MOD;
			(v*=calc(A[n-2],MOD-2,MOD))%=MOD;
		}
		for (int i=0;i<len;i++)
			if (m+i>0){
				v=v*(m+i+n-2)%MOD*ni(m+i)%MOD;
				(ans+=sqr(m+i)*cp[i]%MOD*A[n-2]%MOD*v%MOD)%=MOD;
			}
		v=1;
		if (m>0){
			v=1;
			for (int i=1;i<=n-1;i++)
				(v*=(m+i-1)%MOD)%=MOD;
			(v*=calc(A[n-1],MOD-2,MOD))%=MOD;
		}
		for (int i=0;i<len;i++)
			if (m+i>0){
				v=v*(m+i+n-1)%MOD*ni(m+i)%MOD;
				(ans+=sqr(m+i)*ap[i]%MOD*2%MOD*A[n-1]%MOD*v%MOD)%MOD;
			}
		
		printf("%d\n",(int)ans);
	}
	return 0;
}
