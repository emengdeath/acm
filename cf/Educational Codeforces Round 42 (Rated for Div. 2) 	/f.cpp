#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,m;
int h[N],fa[N][17],l[N],deep[N],f[N*4][2],b[N][2],bz[N],e[N][2],ans[N],tag[N];
vector<int>g[N];
void dfs(int x){
    for (int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
    deep[x]++;
    bz[x]=1;
    for (auto i:g[x])
        if (!bz[i]){
            fa[i][0]=x;
            deep[i]=deep[x];
            dfs(i);
            if (b[i][1]+1>b[x][1])
                b[x][1]=b[i][1]+1,b[x][0]=i;
        }
}
void dfs1(int x){
    static int sum=0;
    l[x]=++sum;
    bz[x]=2;
    if (b[x][0])
        h[b[x][0]]=h[x],dfs1(b[x][0]);
    for (auto i:g[x])
        if (bz[i]<2)
            h[i]=i,dfs1(i);
}
int getlca(int x,int y){
    int i=16;
    if (deep[x]<deep[y])swap(x,y);
    while (deep[x]!=deep[y]){
        while (deep[fa[x][i]]<deep[y])i--;
        x=fa[x][i];
    }
    i=16;
    while (x!=y){
        while (i&&fa[x][i]==fa[y][i])i--;
        x=fa[x][i],y=fa[y][i];
    }
    return x;
}
int up(int x,int dep){
    int i=16;
    while (deep[x]!=dep){
        while (deep[fa[x][i]]<dep)i--;
        x=fa[x][i];
    }
    return x;
}
void down(int l,int r,int s){
    if (f[s][1]){
        f[s][0]+=f[s][1];
        if (l!=r)
            f[s+s][1]+=f[s][1],f[s+s+1][1]+=f[s][1];
        f[s][1]=0;
    }
}
void ins(int l,int r,int s,int ll,int rr){
    down(l,r,s);
    if (r<ll||rr<l)return;
    if (ll<=l&&r<=rr){
        f[s][1]++;
        down(l,r,s);
        return;
    }
    ins(l,(l+r)/2,s+s,ll,rr),ins((l+r)/2+1,r,s+s+1,ll,rr);
    f[s][0]=max(f[s+s][0],f[s+s+1][0]);
}
int get(int l,int r,int s,int ll,int rr){
    down(l,r,s);
    if (r<ll||rr<l)return 0;
    if (ll<=l&&r<=rr)return f[s][0];
    return max(get(l,(l+r)/2,s+s,ll,rr),get((l+r)/2+1,r,s+s+1,ll,rr));
}
bool up(int x,int y,bool sig){
    while (1){
        if (deep[h[x]]<=deep[y]){
            int L=l[y],R=l[x];
            if (!sig){
                ins(1,n,1,L,R);
                return 1;
            }else
                return get(1,n,1,L,R)==1;        
        }else{
            int L=l[h[x]],R=l[x];
            if (!sig)ins(1,n,1,L,R);
            else
            if (get(1,n,1,L,R)>1)return 0;
            x=fa[h[x]][0];
        }
    }
}
void dfs2(int x){
    bz[x]=3;
    for (auto i:g[x])
        if (bz[i]!=3){
            dfs2(i);
            tag[x]+=tag[i];
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
        e[i][0]=x,e[i][1]=y;
    }
    for (int i=1;i<=n;i++)
        if (!bz[i]){
            dfs(i);
            h[i]=i;
            dfs1(i);
        }
    for (int i=1;i<=m;i++){
        int x=e[i][0],y=e[i][1];
        if (deep[x]<deep[y])swap(x,y);
        if (fa[x][0]==y)continue;
        int lca=getlca(x,y);
        if (lca!=y){
            int yy=up(y,deep[lca]+1);
            up(y,yy,0);
        }
        int xx=up(x,deep[lca]+1);
        up(x,xx,0);
    }
    for (int i=1;i<=m;i++){
        int x=e[i][0],y=e[i][1];
        if (deep[x]<deep[y])swap(x,y);
        if (fa[x][0]==y)continue;
        int lca=getlca(x,y);
        if (lca!=y){
            int yy=up(y,deep[lca]+1);
            if (!up(y,yy,1))continue;
        }
        int xx=up(x,deep[lca]+1);
        if (up(x,xx,1)){
            ans[++ans[0]]=i;
            tag[x]++;
            tag[lca]--;
            tag[y]++;
            tag[lca]--;
        }
    }
    for (int i=1;i<=n;i++)
        if (bz[i]!=3)
            dfs2(i);
     for (int i=1;i<=m;i++){
        int x=e[i][0],y=e[i][1];
        if (deep[x]<deep[y])swap(x,y);
        if (fa[x][0]==y){
            if (tag[x])ans[++ans[0]]=i;
        }
    }
    sort(ans+1,ans+ans[0]+1);
    cout<<ans[0]<<endl;
    for (int i=1;i<=ans[0];i++)
        cout<<ans[i]<<' ';
    return 0;
}
