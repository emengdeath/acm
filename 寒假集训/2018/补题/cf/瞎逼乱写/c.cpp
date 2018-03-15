#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
int ans[N],a[N];
char s[N],t[N],s1[N];
int n;
void work(int x){
	int len=0;
	for (int i=1;i<=x;i++)s1[len++]=s[n-i];
	for (int i=0;i<n-x;i++)s1[len++]=s[i];
	for (int i=0;i<n;i++)s[i]=s1[i];
}
void work(int x,int all){
	int one=x,two=1,three=all-x-1,four=n-all;
	ans[++ans[0]]=n;
	work(n);
	ans[++ans[0]]=one+two;
	work(one+two);
	ans[++ans[0]]=three;
	work(three);
}
int main(){
	scanf("%d",&n);
	scanf(" %s",s);
	scanf(" %s",t);
	int l=n/2;
	int r=l;
	for (int i=0;i<n;i++)
		if (t[l]==s[i]){
			ans[++ans[0]]=n-i-1;
			work(n-i-1);
			break;
		}
	if (!ans[0]){
		printf("-1");
		return 0;
	}
	int all=n-1;
	while (l-1>=0||r+1<n){
		int x;
		if (l-1>=0){
			l--;
			x=-1;
			for (int i=0;i<all;i++)
				if (s[i]==t[l]){
					x=i;
					break;
				}
			if (x==-1){
				printf("-1");
				return 0;
			}
			work(x,all);
			all--;
		}
		if (r+1<n){
			r++;
			x=-1;
			for (int i=0;i<all;i++)
				if (s[i]==t[r]){
					x=i;
					break;
				}
			if (x==-1){
				printf("-1");
				return 0;
			}
			work(x,all);
			all--;
		}
	}
	bool sig=1;
	for (int i=0;i<n;i++)if (s[i]!=t[i])sig=0;
	if (!sig){
		work(n);
		ans[++ans[0]]=n;
	}
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	return 0;	
}
