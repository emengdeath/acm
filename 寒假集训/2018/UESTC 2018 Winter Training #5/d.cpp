#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000
#include<cstring>
using namespace std;
char a[N][N],step[N*N*3];
int b[2][2];
int n,len;
char changelr(char c){
	switch(c){
		case '<':return '>';
		case '>':return '<';
		case '^':return '^';
		case 'v':return 'v';
		case 'o':return 'o';
		case 'x':return 'x';
		case '|':return '|';
		case '-':return '-';
		case '/':return '\\';
		case '\\':return '/';
	}
}
char changerotate(char c){
	switch(c){
		case '<':return '^';
		case '>':return 'v';
		case '^':return '>';
		case 'v':return '<';
		case 'o':return 'o';
		case 'x':return 'x';
		case '|':return '-';
		case '-':return '|';
		case '/':return '\\';
		case '\\':return '/';
	}
}
void fliplr(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=(n+1)/2;j++){
			char x=changelr(a[i][j]),y=changelr(a[i][n-j+1]);
			a[i][j]=y,a[i][n-j+1]=x;
		}
}
void rotate(){
	int x=1,len=n,y=n;
	while (len>0){
		if (len==1){
			a[x][x]=changerotate(a[x][x]);
		}else{
			for (int i=0;i<len-1;i++){
				char c1=changerotate(a[x][x+i]),c2=changerotate(a[x+i][y]),c3=changerotate(a[y][y-i]),c4=changerotate(a[y-i][x]);
				a[x+i][y]=c1,a[y][y-i]=c2,a[y-i][x]=c3,a[x][x+i]=c4;
			}
		}
		x++;
		y--;
		len-=2;
	}
}
int main(){
	freopen("d.in","r",stdin);
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;i++)
			scanf(" %s",a[i]+1);
		getchar();
		gets(step);
		b[0][0]=1,b[0][1]=2,b[1][0]=4,b[1][1]=3;
		len=strlen(step);
		for (int i=0;i<=len;i+=2)
			if (step[i]=='<'){
				int x=b[0][0];
				b[0][0]=b[0][1];
				b[0][1]=b[1][1];
				b[1][1]=b[1][0];
				b[1][0]=x;
			}else
			if (step[i]=='>'){
				int x=b[0][0];
				b[0][0]=b[1][0];
				b[1][0]=b[1][1];
				b[1][1]=b[0][1];
				b[0][1]=x;
			}else
			if (step[i]=='-'){
				swap(b[0][0],b[1][0]);
				swap(b[0][1],b[1][1]);
			}else
			if (step[i]=='|'){
				swap(b[0][0],b[0][1]);
				swap(b[1][0],b[1][1]);
			}else
			if (step[i]=='\\'){
				swap(b[1][0],b[0][1]);
			}else
			if (step[i]=='/')
				swap(b[1][1],b[0][0]);
		if (b[0][0]==1){
			if (b[0][1]==2){
			}else{
				rotate();fliplr();
			}
		}else
		if (b[0][0]==4){
			if (b[0][1]==1)rotate();
			else{
				rotate();rotate();fliplr();
			}
		}else
		if (b[0][0]==3){
			if (b[0][1]==4){
				rotate();rotate();
			}else{
				fliplr();
				rotate();
			}
		}else
		if (b[0][1]==3){
			rotate();rotate();rotate();
		}else{
			fliplr();
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)printf("%c",a[i][j]);
			printf("\n");
		}
	
	}
	return 0;
}
