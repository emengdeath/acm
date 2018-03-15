#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 2000
using namespace std;
int a[N];
int T,n;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= 1000; i++) a[i] = 0;
		while (n--) {
			int x;
			scanf("%d", &x);
			a[x]++;
		}
		for (int i = 0; i <= 1000; i++) n = max(n, a[i]);
		for (int i = 0; i <= 1000; i++) 
			if (n == a[i]){
				printf("%d\n", i);
				break;
			}	
	}
	return 0;
}
