#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9+7;
const int maxn = 20;

int n, m;
int dp[1<<20][20];
vector<int> from[maxn];


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        from[--b].push_back(--a);
    }

    // initial dp
    dp[1][0] = 1;

    for(int s = 2; s < (1<<n); s++) {
        if(!(s&1)) continue;
        if(s&(1<<(n-1)) && s != (1<<n)-1) continue;

        for(int x = 0; x < n; x++) {
            if(!(s&(1<<x))) continue;

            int prev = s&(~(1<<x));
            for(int e : from[x]) {
                if((s & (1<<e))) {
                    dp[s][x] += dp[prev][e];
                    dp[s][x] %= MOD;
                }
            }
        }
    }

    cout << dp[(1<<n)-1][n-1] << endl;

    return 0;
}
