#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, a, b;
vector<int> adj[maxn];
int dp[2][maxn];

/*
 * 0 means won't select it,
 * 1 means select it as edge's first node;
 * dp[0][s] = sum(max(dp[0][u], dp[1][u]))
 * dp[1][s] = max(dp[0][u_1] + max(dp[0][u_2], dp[1][u_2])) + 1;
 */
void dfs(int s, int e) {
    dp[0][s] = 0;
    dp[1][s] = 0;
    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs(u, s);
    }

    for(auto u : adj[s]) {
        if(u == e) continue;
        dp[0][s] += max(dp[0][u], dp[1][u]);
    }

    for(auto u : adj[s]) {
        if(u == e) continue;
        dp[1][s] = max(dp[1][s], dp[0][s] + (dp[0][u] > dp[1][u] ? 0 : dp[0][u] - dp[1][u]) + 1);
    }
}


int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int st = 0;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) {
            st = i;
            break;
        }
    }

    dfs(st, 0);
    cout << max(dp[1][st], dp[0][st]) << endl;
    return 0;
}

