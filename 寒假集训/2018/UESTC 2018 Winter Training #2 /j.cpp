#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][2],b[10][3],list[10];
bool bz[10];
int ans;
int main(){
	for (int i=0;i<10;i++)scanf("%d %d",&a[i][0],&a[i][1]);
	for (int i=0;i<10;i++)scanf("%d %d %d",&b[i][0],&b[i][1],&b[i][2]);
	ans=0;
	for (int j=0;j<3;j++){
		for (int i=0;i<10;i++){
			b[i][2]+=max(0,(ans-b[i][2])/(b[i][0]+b[i][1])*(b[i][0]+b[i][1]));
			if (b[i][2]<=ans){
				ans=max(ans,b[i][2]+b[i][0]);
				ans+=a[i][0]+a[i][1];
				b[i][2]=max(ans-a[i][1],b[i][2]+b[i][0]+b[i][1]);
			}else{
				ans+=a[i][0]+a[i][1];
				b[i][2]=max(b[i][2],ans-a[i][1]);
			}
		}
	}
	printf("%d\n",ans-a[9][1]);
	return 0;
}
