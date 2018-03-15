#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000
#include<cstring>
using namespace std;
char s[N],a[N];
int main(){
	a[0]=' ';
	a[5]='A';
	a[67]='B';
	a[70]='C';
	a[22]='D';
	a[1]='E';
	a[43]='F';
	a[25]='G';
	a[40]='H';
	a[4]='I';
	a[53]='J';
	a[23]='K';
	a[49]='L';
	a[8]='M';
	a[7]='N';
	a[26]='O';
	a[52]='P';
	a[77]='Q';
	a[16]='R';
	a[13]='S';
	a[2]='T';
	a[14]='U';
	a[41]='V';
	a[17]='W';
	a[68]='X';
	a[71]='Y';
	a[76]='Z';
	while (scanf("%s",s+1)!=EOF){
		int n;
		n=strlen(s+1);
		int x=1;
		while (x<=n){
			int y=x;
			while (y<=n&&s[y]!='/')y++;
			int v=0;
			for (int i=x;i<y;i++)
				if (s[i]=='.')v=v*3+1;
				else
					v=v*3+2;
			printf("%c",a[v]);
			x=y+1;
		}
		printf("\n");
	}
	return 0;
}
