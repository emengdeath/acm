#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;
int pwr(int a, int b) {
    int r = 1;
    while(b) {
        if(b % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        b /= 2;
    }
    return r;
}
ll ct[nax];
int main() {
	freopen("input","r",stdin);
        int n;
        scanf("%d", &n);
        set<ll> s;
        for(int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            s.insert(a);
            ct[a]++;
        }
        ll res = 0;
        for(ll a : s) for(ll b : s) {
                ll mul;
                if(a != b) mul = ct[a] * ct[b] % mod;
                else mul = ct[a] * (ct[b] - 1) % mod;
                mul = mul * (a + b - 2) % mod;
                ll tmp1  = (a - 1) * (a - 2) / 2 % mod;
                ll tmp2 = (b - 1) * (b - 2) / 2 * (b - 3) / 3 % mod;
                res += mul * tmp1 % mod * tmp2 % mod;
                res %= mod;
            }
        res = res * pwr(n - 2, mod - 2) % mod;
        printf("%lld\n", res);
    return 0;
}

