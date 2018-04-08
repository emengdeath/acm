#include<bits/stdc++.h>
using namespace std;
const int N=100;
int T,A;
bool a[N][N];
bool check(int x,int y){
    for (int i=-1;i<=1;i++)
        for (int j=-1;j<=1;j++)
            if (a[x+i][y+j]==0)return 0;
    return 1;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&A);
        int x=3,y=max((A/3)+(A%3>0),3);
        for (int i=4;i<=A/3;i++){
            int z=max((A/i)+(A%i>0),3);
            if (z<i)break;
            if (z*i<x*y)x=i,y=z;
        }
        memset(a,0,sizeof(a));
        bool sig=0;
        for (int i=3;i-2>=1&&i-2+1<x&&!sig;i+=3){
            while (i-2+1>=x)i--;
            for (int j=3;j-2>=1&&j-2+1<y&&!sig;j+=3){
                while (j-2+1>=y)j--;
                while (!check(i,j)&&!sig){
                    printf("%d %d\n",i,j);
                    fflush(stdout);
                    int xx,yy;
                    scanf("%d %d",&xx,&yy);
                    if (!xx)sig=1;
                    a[xx][yy]=1;
                }
            }
        }
        if (!sig)
        scanf("%d %d",&x,&y);
    }
    return 0;
}
