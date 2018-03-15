#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
#define ph push
#define pb push_back
const int M=1e5+5;
vec G[M];
inline void Max(int &a,int b){
    if(a<b)a=b;
}
inline void Min(int &a,int b){
    if(a>b)a=b;
}
inline void rd(int &a){
    a=0;char c;
    while(c=getchar(),!isdigit(c));
    do a=a*10+(c^48);
        while(c=getchar(),isdigit(c));
}
ll dp[M];
int sz[M];
bool mark[M];
void dfs(int v,int f){
    bool flag=0;
    for(int i=0;i<G[v].size();++i){
        int to=G[v][i];
        if(to==f)continue;
        dfs(to,v);
        if(sz[to]&1)++dp[v];
        else dp[v]+=2;
        dp[v]+=dp[to];
        sz[v]+=sz[to];
        flag=1;
    }
    if(!flag)mark[v]=1,sz[v]=1;
}
int Mx=0;
inline void rdfs(int v,int f,int dlt){
    Max(Mx,dlt);
    for(int i=0;i<G[v].size();++i){
        int to=G[v][i];
        if(to^f)rdfs(to,v,dlt+(sz[to]&1?-1:1));
    }
}
inline void gao(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)G[i].clear();
    memset(dp,0,sizeof(dp));
    memset(sz,0,sizeof(sz));
    Mx=0;
    for(int i=1,a,b;i<n;++i){
        rd(a),rd(b);
        G[a].pb(b),G[b].pb(a);
    }
    int s;
    for(int i=1;i<=n;++i)
        if(G[i].size()==1)s=i;
    dfs(s,s);
    rdfs(s,s,0);
    ++sz[s];
    if(sz[s]&1)cout<<dp[s]-Mx<<endl;
    else cout<<dp[s]<<endl;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("did.out","w",stdout);
    int _;
    for(cin>>_;_--;)gao();
    return 0;
}
