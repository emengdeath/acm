#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000000
#include<cstring>
using namespace std;
char s[N];
int n;
int main(){
	scanf("%s",s);
	n=strlen(s);
	/*for (int i=0;i+25<n;i++){
		bz=1;
		for (int j=0;j<26&&bz;j++)
			if (s[j+i]<=j+'a')
				bz=1;
			else{
				bz=0;
			}
		if (bz){
			for (int j=0;j<26;j++)
				s[j+i]='a'+j;
			break;
		}
	}*/
	int j=0;
	for (int i=0;i<n&&j<26;i++)
		if (s[i]<=j+'a'){
			s[i]=j+'a';
			j++;
		}
	if (j!=26)printf("-1");
	else
		printf("%s",s);
	return 0;
}
