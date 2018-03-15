#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char s[100];
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int a=0,b=0,x=0;
		for (int i=1;i<=len;i++)
			if (s[i]=='.'){
				x=i;
				break;
			}
		if (!x){
			for (int i=1;i<=len;i++)
				a=a*10+s[i]-'0';
			printf("%d",a);
		}else{
			for (int i=1;i<x;i++)
				a=a*10+s[i]-'0';
			int y=1;
			for (int i=x+1;i<=len;i++)
				b=b*10+s[i]-'0',y*=10;
			int u=0,v=0;
			for (int i=2;i<=128;i+=i){
				for (int j=1;j<=i;j++)
					if ((int)round((double)j/i*y)==b||(int)ceil((double)j/i*y)==b||(int)trunc((double)j/i*y)==b){
						u=j,v=i;
						break;
					}
				if (v){
					break;
				}
			}
			if (!a)printf("%d/%d",u,v);
			else
			if (!b)printf("%d",a);
			else
			printf("%d %d/%d",a,u,v);
		}
		printf("\"\n");
	}
	return 0;
}
