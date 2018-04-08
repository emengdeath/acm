#include<bits/stdc++.h>
using namespace std;
string s;
int v,T;
long long get(){
    long long v=0,z=1;
    for (int i=0;i<s.size();i++)
        if (s[i]=='C')z+=z;
        else
            v+=z;
    return v;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    for (int sig=1;sig<=T;sig++){
        cout<<"Case #"<<sig<<": ";
        cin>>v>>s;
        int sum=0;
        while (get()>v){
            bool sig=0;
            for (int i=s.size()-1;i;i--)
                if (s[i]=='S'&&s[i-1]=='C'){
                    swap(s[i],s[i-1]);
                    sig=1;
                    break;        
                }
            if (!sig){
                sum=-1;
                break;
            }
            sum++;
        }
        sum==-1?cout<<"IMPOSSIBLE"<<endl:cout<<sum<<endl;
    }
    return 0;
}
