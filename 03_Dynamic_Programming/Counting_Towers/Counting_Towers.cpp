#include<iostream>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
int t, n;
long long dp[maxn][6];

inline void move(int df) {
    long long *d = dp[df - 1];
    dp[df][0] = (d[0] + d[1] + d[2] + d[3] + d[4] + d[5]) % MOD;
    dp[df][1] = (d[0] + d[1] + d[2] + d[3] + d[4] + d[5]) % MOD;
    dp[df][2] = (d[0] + d[2] + d[3] + d[4]) % MOD;
    dp[df][3] = (d[0] + d[2] + d[3] + d[4]) % MOD;
    dp[df][4] = (d[0] + d[2] + d[3] + d[4]) % MOD;
    dp[df][5] = (d[1] + d[5]) % MOD;
}

int main() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 0;
    dp[0][3] = 0;
    dp[0][4] = 0;
    dp[0][5] = 0;

    for(int i = 1; i < maxn-1; i++)
        move(i);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        n--;
        int ans = 0;
        for(int j = 0; j < 6; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }
        cout << ans << endl;
    }


    return 0;
}
