#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int T,n;
int a[N],b[N],c[N];
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    for (int sig=1;sig<=T;sig++){
        cout<<"Case #"<<sig<<": ";
        cin>>n;
        a[0]=b[0]=0;
        for (int i=1;i<=n;i++){
            if (i&1)cin>>a[++a[0]];
            else
                cin>>b[++b[0]];
        }
        sort(a+1,a+a[0]+1);
        sort(b+1,b+b[0]+1);
        for (int i=1;i<=n;i++)
            if (i&1)c[i]=a[(i+1)/2];
            else
                c[i]=b[i/2];
        int x=0;
        for (int i=2;i<=n;i++)
            if (c[i]<c[i-1]){
                x=i;
                break;
            }
        x?cout<<x-2<<endl:cout<<"OK"<<endl;
    }
    return 0;
}
