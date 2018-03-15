#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 2000000
#define MOD 1000000007
#include<cstring>
using namespace std;
long long a[N],b[N],help[N],f[N],c[N][2],g[N];
char s[N],s1[N];
int n,head,tail;
long long geta(int l,int r){
	return (a[r]-a[l-1]*help[r-l+1]%MOD+MOD)%MOD;
}
long long getb(int l,int r){
	return (b[l]-b[r+1]*help[r+1-l]%MOD+MOD)%MOD;
}
bool check(int l,int r){
	int rr=l-1,ll=rr-(r-l);
	if (ll<1)return 0;
	return geta(ll,rr)==getb(l,r);
}
int main(){
	scanf("%s",s1);
	n=strlen(s1);
	for (int i=0;i<n/2;i++)s[i*2+1]=s1[i]-'a';
	int x=n;
	for (int i=n/2;i<n;i++)s[x]=s1[i]-'a',x-=2;
	help[0]=1;
	for (int i=1;i<=n;i++)a[i]=(a[i-1]*26+s[i])%MOD,help[i]=help[i-1]*26%MOD;
	for (int i=n;i;i--)b[i]=(b[i+1]*26+s[i])%MOD;
	f[0]=1,g[0]=1;
	int l=1;
	for (int i=1;i<=n;i++){
		if (s[l]!=s[i])l=i;
		if (!head)tail=head=i,g[i]=g[i-1];
		else{
			if ((i&1)!=1){
				int x=head;
				long long sum=0;
				while (x){
					if (!check(x+1,i)){
						c[c[x][0]][1]=c[x][1];
						c[c[x][1]][0]=c[x][0];
						if (head==x)head=c[x][1];
						if (tail==x)tail=c[x][0];
					}else{
						if (x>=l){
							(f[i]+=g[i-1]-g[x+1-1-(i-(x+1))-2]+MOD)%=MOD;
							break;
						}
						(sum+=f[x+1-1-(i-(x+1))-1])%=MOD;
					}
					x=c[x][1];
				}
				(f[i]+=sum)%=MOD;
			}
			g[i]=g[i-1]+f[i];
			if (!head)tail=head=i;
			else
				c[tail][1]=i,c[i][0]=tail,tail=i; 
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
