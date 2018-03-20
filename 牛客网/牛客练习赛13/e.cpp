#include<bits/stdc++.h>
#define N 100
using namespace std;
bool f[2][N*2+1][N][2];
string s;
int n;
int main(){
	std::ios::sync_with_stdio(false); 
	cin>>s;
	cin>>n;
	bool bz=0,bz1=1;
	f[0][0+N][0][0]=1;	
	int len=s.size();
	for (int i=0;i<len;i++,swap(bz,bz1)){
		bool v=0;
		if (s[i]=='F')v=1;
		for (int j=-i;j<=i;j++)
			for (int k=0;k<=n;k++)
				for (int l=0;l<2;l++)
					if (f[bz][j+N][k][l]){
						for (int r=0;r<2;r++)
							if (r)
								f[bz1][j+N+(l*2-1)][k+(v!=r)][l]=1;
							else
								f[bz1][j+N][k+(v!=r)][l^1]=1;
						f[bz][j+N][k][l]=0;
					}
	}
	int ans=0;
	for (int i=-len;i<=len;i++)
		if (f[bz][i+N][n][0]||f[bz][i+N][n][1])
			ans=max(ans,abs(i));
	cout<<ans;
	return 0;
}
