#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 101
#define MAXN 1e9
#include<cstring>
using namespace std;
int maxn[N*100][N],minn[N*100][N],help1[N],help2[N],sum[N*100];
char s[N*N];
int n,x,y;
int work(int sig,int l){
	if ('0'<=s[l]&&s[l]<='9'){
		maxn[sig][0]=s[l]-'0';
		minn[sig][0]=s[l]-'0';
		return l;
	}
	++l;
	maxn[sig][0]=0;
	while (s[l]!=')'){
		if (s[l]=='?'){
			l=work(sig+1,l+1)+1;
			int all=sum[sig+1]+1+sum[sig];
			for (int i=min(sum[sig]+sum[sig+1]+1,x);i>=0;i--){
				help1[i]=help2[i]=MAXN;
				if (i>x||all-i>y)continue;
				for (int j=min(sum[sig],i);j>=0;j--){
					if (sum[sig]-j>y||j>x)continue;
					if (maxn[sig][j]!=MAXN){
						if (i-j-1>=0&&i-j-1<=min(sum[sig+1],x)&&sum[sig+1]-(i-j-1)<=y&&maxn[sig+1][i-j-1]!=MAXN){
							if (help1[i]==MAXN||help1[i]<maxn[sig][j]+maxn[sig+1][i-j-1])
								help1[i]=maxn[sig][j]+maxn[sig+1][i-j-1];
						}	
						if (i-j>=0&&i-j<=min(sum[sig+1],x)&&sum[sig+1]-(i-j)<=y&&minn[sig+1][i-j]!=MAXN){
							if (help1[i]==MAXN||help1[i]<maxn[sig][j]-minn[sig+1][i-j])
								help1[i]=maxn[sig][j]-minn[sig+1][i-j];
						}	
					}
					if (minn[sig][j]!=MAXN){
						if (i-j-1>=0&&i-j-1<=min(sum[sig+1],x)&&sum[sig+1]-(i-j-1)<=y&&minn[sig+1][i-j-1]!=MAXN){
							if (help2[i]==MAXN||help2[i]>minn[sig][j]+minn[sig+1][i-j-1])
								help2[i]=minn[sig][j]+minn[sig+1][i-j-1];
						}	
						if (i-j>=0&&i-j<=min(sum[sig+1],x)&&sum[sig+1]-(i-j)<=y&&maxn[sig+1][i-j]!=MAXN){
							if (help2[i]==MAXN||help2[i]>minn[sig][j]-maxn[sig+1][i-j])
								help2[i]=minn[sig][j]-maxn[sig+1][i-j];
						}	
					}
				}
			}
			sum[sig]=all;
			for (int i=0;i<=min(all,x);i++){
				maxn[sig][i]=help1[i];
				minn[sig][i]=help2[i];
			}
			sum[sig+1]=0;
		}else{
			l=work(sig+1,l)+1;
			sum[sig]=sum[sig+1];
			for (int i=min(sum[sig],x);i>=0;i--){
				maxn[sig][i]=maxn[sig+1][i];
				minn[sig][i]=minn[sig+1][i];
			}		
			sum[sig+1]=0;
		}
	}
	return l;
}
int work1(int sig,int l){
	if ('0'<=s[l]&&s[l]<='9'){
		maxn[sig][0]=s[l]-'0';
		minn[sig][0]=s[l]-'0';
		return l;
	}
	++l;
	maxn[sig][0]=0;
	while (s[l]!=')'){
		if (s[l]=='?'){
			l=work1(sig+1,l+1)+1;
			int all=sum[sig+1]+1+sum[sig];
			for (int i=min(sum[sig]+sum[sig+1]+1,x);i>=0;i--){
				help1[i]=help2[i]=MAXN;
				if (i>x||all-i>y)continue;
				for (int j=min(sum[sig],i);j>=0;j--){
					if (sum[sig]-j>y||j>x)continue;
					if (maxn[sig][j]!=MAXN){
						if (i-j>=0&&i-j<=min(sum[sig+1],x)&&sum[sig+1]-(i-j)<=y&&maxn[sig+1][i-j]!=MAXN){
							if (help1[i]==MAXN||help1[i]<maxn[sig][j]+maxn[sig+1][i-j])
								help1[i]=maxn[sig][j]+maxn[sig+1][i-j];
						}	
						if (i-j-1>=0&&i-j-1<=min(sum[sig+1],x)&&sum[sig+1]-(i-j-1)<=y&&minn[sig+1][i-j-1]!=MAXN){
							if (help1[i]==MAXN||help1[i]<maxn[sig][j]-minn[sig+1][i-j-1])
								help1[i]=maxn[sig][j]-minn[sig+1][i-j-1];
						}	
					}
					if (minn[sig][j]!=MAXN){
						if (i-j>=0&&i-j<=min(sum[sig+1],x)&&sum[sig+1]-(i-j)<=y&&minn[sig+1][i-j]!=MAXN){
							if (help2[i]==MAXN||help2[i]>minn[sig][j]+minn[sig+1][i-j])
								help2[i]=minn[sig][j]+minn[sig+1][i-j];
						}	
						if (i-j-1>=0&&i-j-1<=min(sum[sig+1],x)&&sum[sig+1]-(i-j-1)<=y&&maxn[sig+1][i-j-1]!=MAXN){
							if (help2[i]==MAXN||help2[i]>minn[sig][j]-maxn[sig+1][i-j-1])
								help2[i]=minn[sig][j]-maxn[sig+1][i-j-1];
						}	
					}
				}
			}
			sum[sig]=all;
			for (int i=0;i<=min(all,x);i++){
				maxn[sig][i]=help1[i];
				minn[sig][i]=help2[i];
			}
			sum[sig+1]=0;
		}else{
			l=work1(sig+1,l)+1;
			sum[sig]=sum[sig+1];
			for (int i=min(sum[sig],x);i>=0;i--){
				maxn[sig][i]=maxn[sig+1][i];
				minn[sig][i]=minn[sig+1][i];
			}		
			sum[sig+1]=0;
		}
	}
	return l;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d %d",&x,&y);
	if (x>y){
		swap(x,y);
		work1(0,1);	
	}else work(0,1);
	printf("%d",maxn[0][x]);
	return 0;
}
