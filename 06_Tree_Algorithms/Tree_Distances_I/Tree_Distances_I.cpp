#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int dp[3][maxn];
int n, a, b;
vector<int> adj[maxn];
bool vis[maxn];

void dfs_downwards(int s, int e) {
    dp[0][s] = 0;
    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs_downwards(u, s);
        dp[0][s] = max(dp[0][s], dp[0][u]+1);
    }
}

void dfs_upwards(int s, int e) {
    if(e && dp[1][e] == dp[0][s] + 1) dp[1][s] = dp[2][e] + 1;
    else if(e) dp[1][s] = dp[1][e] + 1;

    for(auto u : adj[s]) {
        if(u == e) continue;
        if(dp[1][s] < dp[0][u]+1) {
            swap(dp[1][s], dp[2][s]);
            dp[1][s] = dp[0][u]+1;
        }
        else if(dp[2][s] < dp[0][u]+1) {
            dp[2][s] = dp[0][u]+1;
        }
    }

    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs_upwards(u, s);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_downwards(1, 0);
    dfs_upwards(1, 0);

    for(int i = 1; i <= n; i++)
        cout << dp[1][i] << (i == n ? '\n' : ' ');

    return 0;
}
