#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct point{
    int x,y;
}a[N];
struct Seg{
    int l,r;
}c[N*2],e[N];
struct Node1{
    int l,r,x;
    bool sig;
}b[N];
int n,m,x[2],y[2],calc;
int d[N],f[N*4],u,sig[N*4],fa[N];
bool bz[N];
long long ans;
bool cmp(const Node1&a,const Node1&b){
    return a.x<b.x;
}
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void down(int l,int r,int s){
    if (sig[s]){
        if (sig[s]==-1)f[s]=0;
        else{
            f[s]=sig[s];
        }
        if (l!=r)sig[s+s]=sig[s+s+1]=sig[s];
        sig[s]=0;
    }
}
void get(int l,int r,int s,int ll,int rr){
    down(l,r,s);
    if (c[l].l>=rr||ll>=c[r].r)return;
    if (ll<=c[l].l&&c[r].r<=rr){
        u=max(u,f[s]);
        return;
    }
    get(l,(l+r)/2,s+s,ll,rr),get((l+r)/2+1,r,s+s+1,ll,rr);
}
void getl(int l,int r,int s,int ll){
    down(l,r,s);
    if (l==r){
        u=f[s];
        return;
    }
    if (c[(l+r)/2].r>=ll)getl(l,(l+r)/2,s+s,ll);
    else
        getl((l+r)/2+1,r,s+s+1,ll);
}
void getr(int l,int r,int s,int ll){
    down(l,r,s);
    if (l==r){
        u=f[s];
        return;
    }
    if (c[(l+r)/2+1].l<=ll)getr((l+r)/2+1,r,s+s+1,ll);
    else
        getr(l,(l+r)/2,s+s,ll);
}
void ins(int l,int r,int s,int ll,int rr,int v){
    down(l,r,s);
    if (c[l].l>=rr||ll>=c[r].r)return;
    if (ll<=c[l].l&&c[r].r<=rr){
        sig[s]=v;
        down(l,r,s);
        return;
    }
    ins(l,(l+r)/2,s+s,ll,rr,v),ins((l+r)/2+1,r,s+s+1,ll,rr,v);
    f[s]=max(f[s+s],f[s+s+1]);
}
void build(int l,int r,int s){
    down(l,r,s);
    if (l==r){
        bz[f[s]]=1;
        return;
    }
    build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
}
void build1(int l,int r,int s){
    down(l,r,s);
    if (l==r){
        if (f[s])e[++calc]=c[l];
        f[s]=0;
        return;
    }
    build1(l,(l+r)/2,s+s),build1((l+r)/2+1,r,s+s+1);
    f[s]=0;
}
void combine(int x,int y){
    if (!x||!y)return;
    x=getfa(x),y=getfa(y);
    if (x!=y)
        fa[x]=y;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>x[0]>>y[1]>>x[1]>>y[0];
    cin>>n;
    x[0]++,x[1]++,y[0]++,y[1]++;
    for (int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y,a[i].y++,a[i].x++;
    for (int i=1;i<=n;i++){
        int j=i%n+1;
        if (a[i].x==a[j].x){
            b[++m].l=a[i].y;
            b[m].r=a[j].y;
            if (b[m].l>b[m].r)swap(b[m].l,b[m].r);
            b[m].x=a[i].x;
        }
        d[++d[0]]=a[i].y;   
    }
    d[++d[0]]=y[0],d[++d[0]]=y[1];
    sort(d+1,d+d[0]+1);
    int tot=1;
    for (int i=1;i<=d[0];i++)
        if (d[tot]!=d[i])d[++tot]=d[i];
    d[0]=tot;
    for (int i=1;i<d[0];i++)
        c[i].l=d[i],c[i].r=d[i+1];
    d[0]--;
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=m;i++){
        u=0;
        get(1,d[0],1,b[i].l,b[i].r);
        if (u){
            b[i].sig=1;
            ins(1,d[0],1,b[i].l,b[i].r,-1);
        }else{
            b[i].sig=0;
            ins(1,d[0],1,b[i].l,b[i].r,1);
        }
        b[i].l=max(b[i].l,y[0]),b[i].r=min(b[i].r,y[1]);
    }
    for (int i=1;i<=m;i++){
        if (b[i].l>=b[i].r)continue;
        if (b[i].sig){
            if (b[i].x<=x[0])ins(1,d[0],1,b[i].l,b[i].r,-1);
        }else{
            if (b[i].x<x[0])ins(1,d[0],1,b[i].l,b[i].r,1);
        }
    }
    build1(1,d[0],1);
    int last=1;
    for (int i=2;i<=calc;i++)
        if (e[i].l!=e[i-1].r){
            b[++m].l=e[last].l;
            b[m].r=e[i-1].r;
            b[m].x=x[0];
            b[m].sig=0;            
            last=i;
        }
    if (calc){
        b[++m].l=e[last].l;
        b[m].r=e[calc].r;
        b[m].x=x[0];
        b[m].sig=0;
    }
    sort(b+1,b+m+1,cmp);
    for (int i=1;i<=m;i++){
        fa[i]=i;
        if (b[i].l>=b[i].r)continue;
        if (b[i].x<x[0])continue;
        if (b[i].x>=x[1])break;
        if (b[i].sig){
            if (b[i].x>x[0]){
                u=0;
                get(1,d[0],1,b[i].l,b[i].r);
                bz[u]=1;
            }
            ins(1,d[0],1,b[i].l,b[i].r,-1);
        }else{
            if (b[i].l!=y[0]){
                u=0;
                getl(1,d[0],1,b[i].l);    
                combine(u,i);
            }
            if (b[i].r!=y[1]){
                u=0;
                getr(1,d[0],1,b[i].r);
                combine(u,i);
            }
            ins(1,d[0],1,b[i].l,b[i].r,i);            
        }
    }
    build(1,d[0],1);
    for (int i=1;i<=m;i++)
        if (bz[i])bz[getfa(i)]=1;
    for (int i=1;i<=m;i++)
        if (getfa(i)==i&&bz[i])ans++;
    cout<<ans;
    return 0;
}
