#include<iostream>
#include<vector>
using namespace std;
const int maxn = 2e5 + 5;
int n, a, b;
vector<int> adj[maxn];
long long dp[4][maxn];

/*
 * dp[0] upwards distances sum
 * dp[1] upwards node count
 * dp[2] downward distances sum
 * dp[3] downward node count 
 */

void dfs_downward(int s, int e) {
    dp[2][s] = 0;
    dp[3][s] = 1;
    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs_downward(u, s);
        dp[2][s] += dp[2][u] + dp[3][u];
        dp[3][s] += dp[3][u];
    }
}

void dfs_upward(int s, int e) {
    dp[1][s] = 1;
    // if(e) dp[0][s] = dp[0][e] + dp[1][e] + dp[2][e] + dp[3][e] - dp[2][s] - dp[3][s];
    if(e) dp[0][s] = dp[0][e] + dp[1][e] + dp[2][e] - dp[2][s] - dp[3][s] + dp[3][e] - dp[3][s] - 1;
    if(e) dp[1][s] += dp[1][e] + dp[3][e] - dp[3][s] - 1;

    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs_upward(u, s);
    }
}


int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_downward(1, 0);
    dfs_upward(1, 0);

    for(int i = 1; i <= n; i++) {
        // cout << dp[0][i] << " " << dp[2][i] << endl; //(i == n ? '\n' : ' ');
        cout << dp[0][i] + dp[2][i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
