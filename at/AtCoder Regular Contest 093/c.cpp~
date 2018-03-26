#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
int a[N];
ll ans;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],ans+=abs(a[i]-a[i-1]);
    ans+=abs(a[n]);
    for (int i=1;i<=n;i++)
        cout<<ans-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1])<<endl;
    return 0;
}
