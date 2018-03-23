#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	double m=fmod(n,acos(-1)*2);
	printf("%.9lf",max(sin((double)m/3),sin(((double)m+2*acos(-1))/3))*3);
	return 0;
}
