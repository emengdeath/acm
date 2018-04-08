#include<bits/stdc++.h>
//#include<hash_map>
using namespace std;
//using namespace __gnu_cxx;
const int N=1e7;
int T;
int a[N],d[N],b[N];
int n;
map<int,int>f;
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin>>n;
        f.clear();
        a[0]=1,a[1]=0;
        int sum=0;
        for (int i=1;i<(1<<n);i++)cin>>b[i];
        sort(b+1,b+(1<<n));
        for (int i=1;i<(1<<n);i++){
            int x;
            x=b[i];
            if (f[x]){
                f[x]--;
                continue;
            }
            d[++sum]=x;
            if (sum>n)break;
            for (int j=a[0];j;j--)
                if (a[j]+x>2e9){
                    sum=n+1;
                    break;
                }else
                f[a[++a[0]]=a[j]+x]++;
            f[x]--;
            if (sum>n)break;
        }
        if (sum==n){
            for (int i=1;i<sum;i++)
                cout<<d[i]<<" ";
            cout<<d[sum]<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}
