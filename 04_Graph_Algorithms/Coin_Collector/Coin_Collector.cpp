/*
 *  可以用缩点的方法得到有向无环图，之后再图DP求极大值。
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 1e5+5;
vector<int> G[maxn], rG[maxn];
set<int> recG[maxn];
int n, m, color[maxn], coins[maxn];
bool vis[maxn];
long long dp[maxn];
vector<int> dfsorder;

void dfs1(int u) {
    vis[u] = true;
    for(auto v : G[u])
        if(!vis[v]) dfs1(v);
    dfsorder.push_back(u);
}

void dfs2(int u, int components) {
    color[u] = components;
    for(auto v : rG[u])
        if(!color[v]) dfs2(v, components);
}

int SCC() {
    for(int u = 1; u <= n; u++)
        if(!vis[u]) dfs1(u);

    fill(vis, vis + maxn, 0);

    int components = 0;
    for(int i = n-1; i >= 0; i--) {
        int u = dfsorder[i];
        if(!color[u]) dfs2(u, ++components);
    }
    return components;
}

void reconstruct() {
    for(int u = 1; u <= n; u++) {
        dp[color[u]] += coins[u];
        for(auto v : G[u]) {
            if(color[v] != color[u])
            recG[color[v]].insert(color[u]);
        }
    }
}

long long dfs(int u) {
    vis[u] = true;
    long long tmp = 0;
    for(auto v : recG[u])
        tmp = max(tmp, (vis[v] ? dp[v] : dfs(v)));
    dp[u] += tmp;
    return dp[u];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> coins[i];

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    int components = SCC();
    reconstruct();
    long long ans = 0;
    for(int u = 1; u <= components; u++)
        if(!vis[u]) ans = max(ans, dfs(u));

    cout << ans << endl;

    return 0;
}
