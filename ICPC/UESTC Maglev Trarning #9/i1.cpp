#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define M 200
#define N 1000
#include<cmath>
typedef long double LD;
using namespace std;
long long C[M+1][M+1];
long long f[N][401];
int n,T,k;

const LD pi=acos(-1);
const LD eps=0.5;
struct Z{LD x,y;Z(LD X=0,LD Y=0){x=X,y=Y;}};
Z operator +(Z a,Z b){return Z(a.x+b.x,a.y+b.y);}
Z operator -(Z a,Z b){return Z(a.x-b.x,a.y-b.y);}
Z operator *(Z a,Z b){return Z(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}
Z a[N],b[N],tp[N],u,v,wi;
long long g[N],ni[N];
int len;
long long bz[N],ap[N],bp[N],cp[N];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
void DFT(Z*a,int sig){
    for (int i=0;i<len;i++)tp[bz[i]]=a[i];
    for (int i=2,hal,j,k;i<=len;i<<=1)
        for (hal=i>>1,j=0;j<hal;j++){
            wi=Z(cos(j*pi*sig/hal),sin(j*pi*sig/hal));
            for (k=j;k<len;k+=i){
                u=tp[k];
                v=tp[k+hal]*wi;
                tp[k]=u+v;
                tp[k+hal]=u-v;
            }
        }
    for (int i=0;i<len;i++)a[i]=tp[i];
}
void FFT(long long*ap,long long*bp,long long n,long long*cp){
    a[0]=b[0]=0;
    for (int i=0;i<len;i++)a[i]=ap[i],b[i]=bp[i];
    for (int i=0,j,k,l;i<len;bz[k]=i++)
        for (j=i,k=0,l=1;l<len;l<<=1,j>>=1)k=(k<<1)+(j&1);
    DFT(a,1),DFT(b,1);
    for (int i=0;i<len;i++)a[i]=a[i]*b[i];
    DFT(a,-1);
    for (int i=0;i<=n;i++)cp[i]=(long long)(fmod((a[i].x/LD(len)+eps),MOD))%MOD;
}
int main(){
	freopen("i.in","r",stdin);
	scanf("%d",&T);
	f[0][0]=1;
	g[0]=1;
	for (int i=1;i<=M;i++)g[i]=g[i-1]*i%MOD;
	ni[M]=calc(g[M],MOD-2);
	for (int i=M-1;i>=0;i--)ni[i]=ni[i+1]*(i+1)%MOD;
    for (len=1;len<=400;len<<=1);
	while (T--){
		scanf("%d %d",&n,&k);
		for (int i=1;i<=n;i++)
			for (int j=0;j<=k;j++)f[i][j]=0;
		for (int i=1;i<=n;i++){
			char c;
			scanf(" %c",&c);
			c-='0';
			long long v=1;
			for (int j=0;j<=len;j++)ap[j]=bp[j]=0;
			for (int j=0;j<=100;j++){
				ap[j]=v%MOD;
				bp[j]=f[i-1][j]%MOD;
				(v*=c)%=MOD;
			}
			FFT(ap,bp,k,f[i]);
			f[i][0]=i+1;
		}
		printf("%lld",f[1][k]);
		for (int i=2;i<=n;i++)
			printf(" %lld",f[i][k]);
		printf("\n");
	}
	return 0;
}
