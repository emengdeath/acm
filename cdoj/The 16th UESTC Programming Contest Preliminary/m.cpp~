#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n;
int T;
ll a[100],b[1000000];
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--){
		cin>>n;
		a[0]=0;
		for (int i=1;i<=n;i++)
			cin>>b[i];
		sort(b+1,b+n+1);
		int tot=n;
		n=1;
		for (int i=1;i<=tot;i++)
			if (b[i]!=b[n])b[++n]=b[i];
		for (int i=1;i<=n;i++){
			ll x=b[i];
			for (int j=a[0];j;j--)
				if ((x^a[j])<x)x^=a[j];
			if (x){
				for (int j=1;j<=a[0];j++)
					if ((a[j]^x)<a[j])a[j]^=x;
				a[++a[0]]=x;
				sort(a+1,a+a[0]+1);
			}
		}
		cout<<((1<<a[0])-n);
	}
	return 0;
}
