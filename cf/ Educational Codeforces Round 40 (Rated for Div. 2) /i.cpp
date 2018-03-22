#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
typedef long long ll;
const LD pi=acos(-1);
const LD eps=0.5;
const int N=500000;
string s,t;
int n,len;
int bz[N],ap[N],bp[N],cp[N],fa[6];
int f[N][6][6];
struct Z{LD x,y;Z(LD X=0,LD Y=0){x=X,y=Y;}};
Z operator +(Z a,Z b){return Z(a.x+b.x,a.y+b.y);}
Z operator -(Z a,Z b){return Z(a.x-b.x,a.y-b.y);}
Z operator *(Z a,Z b){return Z(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}
Z a[N],b[N],tp[N],u,v,wi;
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
void FFT(int*ap,int*bp,int n){
	for (len=1;len<=n;len<<=1);
	a[0]=b[0]=0;
	for (int i=0;i<len;i++)a[i]=ap[i],b[i]=bp[i];
	for (int i=0,j,k,l;i<len;bz[k]=i++)
		for (j=i,k=0,l=1;l<len;l<<=1,j>>=1)k=(k<<1)+(j&1);
	DFT(a,1),DFT(b,1);
	for (int i=0;i<len;i++)a[i]=a[i]*b[i];
	DFT(a,-1);
	for (int i=0;i<=n;i++)cp[i]=ll(a[i].x/LD(len)+eps);
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	cin>>t;
	for (int i=0;i<s.size();i++)
		s[i]-='a';
	for (int i=0;i<t.size();i++)
		t[i]-='a';
	for (int i=0;i<6;i++)
		for (int k=0;k<6;k++)
		if (i!=k){
			for (int j=0;j<s.size();j++)
				ap[j]=(s[j]==i);
			for (int j=0;j<t.size();j++)
				bp[t.size()-j-1]=(t[j]==k);
			FFT(ap,bp,s.size());
			for (int j=0;j<=s.size()-t.size();j++)
				f[j][i][k]=(cp[j+t.size()-1]>0);
		}
	for (int i=0;i<=s.size()-t.size();i++){
		int ans=0;
		for (int j=0;j<6;j++)fa[j]=j;
		for (int j=0;j<6;j++)	
			for (int k=0;k<6;k++)
				if (f[i][j][k]&&getfa(j)!=getfa(k))ans++,fa[fa[j]]=fa[k];
		cout<<ans<<' ';
	}
	return 0;
}
