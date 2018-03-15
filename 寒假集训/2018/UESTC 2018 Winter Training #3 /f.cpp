#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200000][3];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	for (int i=1;i<=n;i++){
		if (a[i][0]+a[i][1]<=a[i][2]||a[i][1]+a[i][2]<=a[i][0]||a[i][2]+a[i][0]<=a[i][1]){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
