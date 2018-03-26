#include<bits/stdc++.h>
using namespace std;
#define map map1
bool map[100][100];
int main(){
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    cout<<"100 100"<<endl;
    a--,b--;
    for (int i=0;i<50;i++)
        for (int j=0;j<100;j++)map[i][j]=1;
    int x=0,y=0;
    while (a--){
        map[x][y]=0;
        y+=2;
        if (y==100){
            x+=2;
            y=0;
        }
    }
    x=51,y=0;
    while (b--){
        map[x][y]=1;
        y+=2;
        if (y==100){
            x+=2;
            y=0;
        }
    }
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++)
            if (map[i][j])cout<<'#';
            else
                cout<<'.';
        cout<<endl;
    }
    return 0;
}
