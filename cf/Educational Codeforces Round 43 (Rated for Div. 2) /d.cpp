#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N],b[N],d[N],sum;
struct node{
    int x,y;
}e[N];
bool cmp(const node&a,const node&b){
    return a.y<b.y;
}
bool check(){
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=b[i];j++)d[++tot]=a[i];
    while (d[tot]){
        for (int i=tot-1;i&&d[i]&&d[tot];i--)
            d[i]--,d[tot]--;
        if (d[tot]){
            sum=d[tot];
            return 0;
        }
        tot--;
        sort(d+1,d+tot+1);
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i],b[i]=1;
    b[1]+=a[n]+1-n;
    while (!check()){
        for (int i=1;i<=n&&sum;i++){
            int s=min(max(b[i]-2,0),sum);
            b[i]-=s,b[i+1]+=s,sum-=s;
        }
    }
    int all=0;
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=b[i];j++)++tot,e[tot].x=tot,all+=(e[tot].y=a[i]);
    n=tot;
    sort(e+1,e+n+1,cmp);
    cout<<all/2<<endl;
    while (e[n].y){
        for (int i=n-1;e[n].y;i--) 
            e[i].y--,e[n].y--,cout<<e[i].x<<' '<<e[n].x<<endl;
        n--;
        sort(e+1,e+n+1,cmp);
    }
    return 0;
}
