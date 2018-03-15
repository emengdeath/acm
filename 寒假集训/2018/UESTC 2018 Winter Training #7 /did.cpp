    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <algorithm>  
    #include <string>  
    #include <cmath>  
    #include <queue>  
    #include <stack>  
    #include <set>  
    #include <map>  
    #include <cstdlib>  
    using namespace std;  
      
    #define LL long long  
    #define inf 0x3f3f3f3f  
    #define eps 1e-8  
    #define ULL unsigned long long  
    #define mnx 420  
    #define mxe 10020  
    #define mxnode 20020  
    #define mod 1000000007  
      
      
    char g[22][22];  
    int n, m, cnt;  
    char s[mnx];  
      
    int dp[20020][22][22];  
    int sx, sy;  
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};  
    bool in(int x, int y) {  
        return x >= 1 && y >= 1 && x <= n && y <= m;  
    }  
    bool inq[20020][22][22];  
    struct trie {  
        int ch[mxnode][26];  
        bool mark[mxnode];  
        int f[mxnode], sz;  
        int creat() {  
            memset(ch[sz], -1, sizeof(ch[sz]));  
            mark[sz] = 0;  
            return sz++;  
        }  
        void init() {  
            sz = 0, creat();  
        }  
        void insert(char *s) {  
            int t = 0;  
            for(int i = 0; s[i]; ++i) {  
                int c = s[i] - 'A';  
                if(!~ch[t][c]) ch[t][c] = creat();  
                t = ch[t][c];  
            }  
            mark[t] = 1;  
        }  
        void build() {  
            queue<int> q; f[0] = 0;  
            for(int i = 0; i < 26; ++i) {  
                int &v = ch[0][i];  
                if(!~v) v = 0;  
                else f[v] = 0, q.push(v);  
            }  
            while(!q.empty()) {  
                int t = q.front(); q.pop();  
                if(mark[f[t]]) mark[t] = 1; //注意要不要加这行  
                for(int i = 0; i < 26; ++i) {  
                    int &v = ch[t][i];  
                    if(!~v) v = ch[f[t]][i];  
                    else {  
                        f[v] = ch[f[t]][i];  
                        q.push(v);  
                    }  
                }  
            }  
        }  
        int spfa() {  
            int ret = inf;  
            memset(inq, 0, sizeof inq);  
            memset(dp, 0x3f, sizeof dp);  
            dp[0][sx][sy] = 0;  
            queue<int> q;  
            q.push(0), q.push(sx), q.push(sy);  
            while(!q.empty()) {  
                int s = q.front(); q.pop();  
                int x = q.front(); q.pop();  
                int y = q.front(); q.pop();  
                inq[s][x][y] = 0;  
                for(int i = 0; i < 4; ++i) {  
                    int dx = x + dir[i][0];  
                    int dy = y + dir[i][1];  
                    if(!in(dx, dy)) continue;  
                    if(g[dx][dy] == '#') continue;  
                    if(g[dx][dy] == '.') {  
                        if(dp[s][dx][dy] <= dp[s][x][y] + 1) continue;  
                        dp[s][dx][dy] = dp[s][x][y] + 1;  
                        if(!inq[s][dx][dy])  
                            inq[s][dx][dy] = 1, q.push(s), q.push(dx), q.push(dy);  
                        continue;  
                    }  
                    int t = ch[s][g[dx][dy]-'A'];  
                    if(dp[t][dx][dy] <= dp[s][x][y] + 1) continue;  
                    dp[t][dx][dy] = dp[s][x][y] + 1;  
                    if(!inq[t][dx][dy])  
                        inq[t][dx][dy] = 1, q.push(t), q.push(dx), q.push(dy);  
                }  
                if(g[x][y] != '.') {  
                    int t = ch[s][g[x][y]-'A'];  
                    if(dp[t][x][y] > dp[s][x][y]) {  
                        dp[t][x][y] = dp[s][x][y];  
                        if(!inq[t][x][y])  
                            inq[t][x][y] = 1, q.push(t), q.push(x), q.push(y);  
                    }  
                }  
            }  
            for(int i = 1; i < sz; ++i) {  
                if(mark[i] == 0) continue;  
                for(int j = 1; j <= n; ++j)  
                    for(int k = 1; k <= m; ++k)  
                        ret = min(ret, dp[i][j][k]);  
            }  
            if(ret == inf) ret = -1;  
            return ret;  
        }  
    }ac;  
      
    int main() {  
        int cas;  
        scanf("%d", &cas);  
        while(cas--) {  
            scanf("%d%d", &n, &m);  
            for(int i = 1; i <= n; ++i)  
                scanf("%s", g[i] + 1);  
            for(int i = 1; i <= n; ++i)  
                for(int j = 1; j <= m; ++j)  
                    if(g[i][j] == '@') {  
                        sx = i, sy = j, g[i][j] = '.';  
                        break;  
                    }  
            ac.init();  
            int q;  
            scanf("%d", &q);  
            while(q--) {  
                scanf("%s", s);  
                ac.insert(s);  
            }  
            ac.build();  
            printf("%d\n", ac.spfa());  
        }  
        return 0;  
    }  	
