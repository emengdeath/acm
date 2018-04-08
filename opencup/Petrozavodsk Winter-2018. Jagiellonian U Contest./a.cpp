#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long all,a[100],b[100],c[N];
int T,n;
long long check(long long x){
    for (int i=a[0];i;i--)
        if ((x^a[i])<x)x^=a[i];
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--){
        cin>>n;
        all=0;
        a[0]=0;
        for (int i=1;i<=n;i++){
            //long long x;
            cin>>c[i];     
            all^=c[i];
        }
        for (int i=1;i<=n;i++){
            long long x=(c[i]&all);
            for (int j=a[0];j;j--)
                if ((x^a[j])<x)x^=a[j];
            if (x){
                for (int j=1;j<=a[0];j++)
                    if ((x^a[j])<a[j])a[j]^=x;
                a[++a[0]]=x;
                sort(a+1,a+a[0]+1);
            }
        }
        b[0]=0;
        sort(a+1,a+a[0]+1);
        while (all)b[++b[0]]=(all&-all),all-=(all&-all);
        long long A=0,B=0;
        A=b[b[0]];
        if (b[0])
        for (int i=b[0]-1;i;i--){
            long long C=check(A);
            if (C/b[i]==0)B+=b[i];
            else
                A+=b[i];
        }
        cout<<A-B<<endl;
    }
    return 0;
}
