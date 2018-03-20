#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	int n,k,A,B;
	cin>>n>>k>>A>>B;
	int N=k*2+1;
	long long b[N][N]={},a[N]={},c[N][N]={};
	a[k/2]=1;
	n-=2;
	for (int i=1;i<=k;i++){
		if (i>1){
			b[i][i-1]=b[i+k][i-1+k]=1;
			if (i-1>A&&i-1<B)
				b[i][i-1+k]=1;
		}
		if (i<k){
			b[i][i+1]=b[i+k][i+1+k]=1;
			if (i+1>A&&i+1<B)
				b[i][i+1+k]=1;
		}
		b[i][i]=b[i+k][i+k]=1;
		if (i>A&&i<B)
			b[i][i+k]=1;
	}
	int nn=n;
	while (n){
		if (n&1){
			for (int i=0;i<N;i++)
				for (int j=0;j<N;j++)
					(c[0][j]+=a[i]*b[i][j]%MOD)%=MOD;		
			for (int i=0;i<N;i++)
				a[i]=c[0][i],c[0][i]=0;
		}
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				for (int k=0;k<N;k++)
					(c[i][k]+=b[i][j]*b[j][k]%MOD)%=MOD;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				b[i][j]=c[i][j],c[i][j]=0;
		n>>=1;
	}
	long long ans=a[k/2+k];
	if (k/2!=k)(ans+=a[k/2+1+k])%=MOD;
	if (k/2!=1)(ans+=a[k/2-1+k])%=MOD;
	cout<<ans*calc(nn,MOD-2)%MOD;
	return 0;	
}
