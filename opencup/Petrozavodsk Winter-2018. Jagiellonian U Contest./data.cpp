#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int main(){
    srand((int)time(0));
    T=10;
    cout<<T<<endl;
    while (T--){
        n=20;
        cout<<n<<endl;
        for (int i=1;i<=n;i++)
            cout<<rand()%100000<<' ';
        cout<<endl;
    }
    return 0;
}
