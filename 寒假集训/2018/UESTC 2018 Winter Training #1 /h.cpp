#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
#include<cstring>
using namespace std;
char s[N];
int T,n,x,y,z,x1,y1,z1,x2,y2,z2;
bool bz[10];
bool check(char c){
	return c=='?'||('0'<=c&&c<='9');
}
void work(int l,int&x,int&x1){
	while (!check(s[l]))l++;
	while (l<n&&check(s[l])){
		x*=10,x1*=10;
		if (s[l]=='?')x1++;
		else
			x+=s[l]-'0';
		l++;
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s);
		n=strlen(s);
		x=y=z=0;
		x1=y1=z1=0;
		x2=y2=z2=1;
		int r,l;
		for (int i=0;i<10;i++)bz[i]=0;
		for (int i=1;i<n;i++){
			if (s[i]=='='){
				r=i;
				break;
			}else
			if ((s[i]=='-'||s[i]=='*'||s[i]=='+')&&check(s[i-1])){
				l=i;
			}
			if ('0'<=s[i]&&s[i]<='9')bz[s[i]-'0']=1;
		}
		for (int i=l+1;i<r&&s[i]=='-';i++)y2*=-1;
		for (int i=0;i<l&&s[i]=='-';i++)x2*=-1;
		for (int i=r+1;i<n&&s[i]=='-';i++)z2*=-1;
		work(0,x,x1);
		work(l+1,y,y1);
		work(r+1,z,z1);
		int ans=-1;
		int xx=0;
		if ((x<x1&&!(x1==1&&x2==1))||(y<y1&&!(y1==1&&y2==1))||(z<z1&&!(z1==1&&z2==1)))xx=1;
		for (int i=xx;i<10;i++)
			if (!bz[i]){
			if (s[l]=='-'){
				if ((x+x1*i)*x2-(y+y1*i)*y2==(z+z1*i)*z2){
					ans=i;
					break;
				}
			}else
			if (s[l]=='+'){
				if ((x+x1*i)*x2+(y+y1*i)*y2==(z+z1*i)*z2){
					ans=i;
					break;
				}
			}else{
				if ((long long)(x+x1*i)*x2*(y+y1*i)*y2==(z+z1*i)*z2){
					ans=i;
					break;
				}
			}}
		printf("%d\n",ans);
	}
	return 0;
}
