#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
#include<cstring>
using namespace std;
long long help[40];
struct node{
	long long x;
	int len;
	node(long long X=0,int LEN=0){x=X,len=LEN;}
	void get(){
		(x/=help[len])*=help[len];
	}
}a[N],b[N],ans[N];
int T,n,totans;
char s[100];
bool cmp(const node&a,const node&b){
	return a.x<b.x||(a.x==b.x&&a.len<b.len);
}
bool inclu(node a,node b){
	if (a.len>b.len)return 0;
	return a.x/help[a.len]==b.x/help[a.len];
}
node lca(node a,node b){
	int x=0;
	while (x<min(a.len,b.len)&&a.x/help[x+1]==b.x/help[x+1])x++;
	a.len=x;
	a.get();
	return a;
}
void update(node a){
	ans[++totans]=a;
}
node work(node a,node b){
	node c=lca(a,b);
	while (a.len!=c.len){
		if (a.len>c.len+1)update(node(a.x^help[a.len],a.len));
		a.len--;
		a.get();
	}
	while (b.len!=c.len){
		if (b.len>c.len+1)update(node(b.x^help[b.len],b.len));
		b.len--;
		b.get();
	}
	return c;
}
int main(){
	freopen("i.in","r",stdin);
	scanf("%d",&T);
	help[32]=1;
	for (int i=31;i>=0;i--)help[i]=help[i+1]*2;
	for (int sig=1;sig<=T;sig++){
		printf("Case #%d:\n",sig);
		scanf("%d",&n);
		if (!n){
			printf("1\n");
			printf("0.0.0.0/0\n");
			continue;
		}
		for (int i=1;i<=n;i++){
			scanf(" %s",s+1);
			int len=strlen(s+1);
			int j=1;
			int y=0;
			a[i].x=a[i].len=0;
			while (s[j]!='/'){
				if (s[j]=='.')a[i].x=(a[i].x<<8)+y,y=0;
				else
					y=y*10+s[j]-'0';
				j++;
			}
			a[i].x=(a[i].x<<8)+y;
			j++;
			while (j<=len){
				a[i].len=a[i].len*10+s[j]-'0';
				j++;
			}
			a[i].get();
		}
		sort(a+1,a+n+1,cmp);
		int x=n;
		n=1;
		for (int i=2;i<=x;i++)
			if (!inclu(a[n],a[i]))a[++n]=a[i];
		int tot=1;
		totans=0;
		b[1]=a[1];
		for (int i=2;i<=n;i++){
			while (tot>1&&inclu(lca(b[tot],a[i]),lca(b[tot-1],b[tot]))){
				b[tot-1]=work(b[tot],b[tot-1]);
				tot--;
			}
			b[++tot]=a[i];
		}
		while (tot>1)b[tot-1]=work(b[tot],b[tot-1]),tot--;
		while (b[tot].len){
			update(node(b[tot].x^help[b[tot].len],b[tot].len));
			b[tot].len--;
			b[tot].get();
		}
		printf("%d\n",totans);
		for (int i=1;i<=totans;i++){
			printf("%d",ans[i].x/help[8]%(1<<8));
			printf(".");
			printf("%d",ans[i].x/help[16]%(1<<8));
			printf(".");
			printf("%d",ans[i].x/help[24]%(1<<8));
			printf(".");
			printf("%d",ans[i].x/help[32]%(1<<8));
			printf("/");
			printf("%d\n",ans[i].len);
		}
	}
	return 0;
}
