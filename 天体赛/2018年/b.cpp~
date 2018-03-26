#include<bits/stdc++.h>
using namespace std;
char s[10];
int h,m;
int dig(char c){
	return c-'0';
}
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	h=dig(s[0])*10+dig(s[1]);
	m=dig(s[3])*10+dig(s[4]);
	if (h<12||(h==12&&!m)){
		cout<<"Only "<<s<<".  Too early to Dang.";
	}else{
		h-=12;
		if (m)h++;
		while (h--)cout<<"Dang";
	}
	return 0;
}
