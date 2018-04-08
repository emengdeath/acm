#include<bits/stdc++.h>
using namespace std;
int a[100];
int n,T,ans;
void dfs(int x,int A,int B){
    if (x>n){
        ans=min(ans,abs(A-B));
        return;
    }
    dfs(x+1,(A^a[x]),B);
    dfs(x+1,A,(B^a[x]));
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        ans=1000000;
        dfs(1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
