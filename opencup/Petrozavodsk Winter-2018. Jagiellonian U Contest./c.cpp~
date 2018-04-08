#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int T,n,sum,v,ans;
int a[N],b[N],c[N],d[N];
struct node{
    int mx;
    int son[2];
    void clear(){
        mx=son[0]=son[1]=0;
    }
}f[N*16*13];
inline int lowbit(int x){
    return x&-x;
}
void get(int l,int r,int s,int a){
    if (!s||d[l]>=a||f[s].mx<=v)return;
    if (d[r]<a){
        v=f[s].mx;
        return;
    }
    get(l,(l+r)/2,f[s].son[0],a),get((l+r)/2+1,r,f[s].son[1],a);
}
void get(int a,int b){
    while (a){
        get(1,d[0],a,b);
        a-=lowbit(a);
    }
}
void ins(int l,int r,int s,int a,int v){
    f[s].mx=max(f[s].mx,v);
    if (l==r)return;
    if (d[(l+r)/2]>=a){
        if (!f[s].son[0])f[s].son[0]=++sum;
        ins(l,(l+r)/2,f[s].son[0],a,v);
    }else{
        if (!f[s].son[1])f[s].son[1]=++sum;
        ins((l+r)/2+1,r,f[s].son[1],a,v);
    }
}
void ins(int a,int b,int v){
    while (a<=c[0]){
        ins(1,d[0],a,b,v);
        a+=lowbit(a);
    }
}
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int er(int x){
    int l=1,r=c[0],mid;
    while (l<=r){
        if (c[mid=(l+r)/2]==x)return mid;
        if (c[mid]>x)r=mid-1;
        else
            l=mid+1;
    }
    if (c[l]==x)return l;
    else
        return r;
}
int main(){
   // freopen("c.in","r",stdin);
    T=read();
    while (T--){
        n=read();
        for (int i=1;i<=n;i++){a[i]=read();c[i]=a[i];}
        for (int i=1;i<=n;i++){b[i]=read();d[i]=b[i];}
        sort(c+1,c+n+1);
        sort(d+1,d+n+1);
        c[0]=1;
        for (int i=2;i<=n;i++)
            if (c[c[0]]!=c[i])c[++c[0]]=c[i];
        d[0]=1;
        for (int i=2;i<=n;i++)
            if (d[d[0]]!=d[i])d[++d[0]]=d[i];
        for (int i=1;i<=sum;i++)f[i].clear();
        sum=c[0];
        ans=0;
        for (int i=1;i<=n;i++){
            v=0;
            int x=er(a[i]);
            get(x,b[i]);
            ins(x+1,b[i],v+1);
            ans=max(ans,v+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
