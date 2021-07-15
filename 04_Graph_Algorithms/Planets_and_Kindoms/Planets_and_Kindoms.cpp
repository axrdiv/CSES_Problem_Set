/*
 * Strongly Connected Components
 */

#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e5+5;
int n, m;
vector<int> G[maxn];
vector<int> rG[maxn];
int vis[maxn];
vector<int> dfsorder;

void dfs1(int u) {
    vis[u] = 1;
    for(auto v : G[u])
        if(!vis[v]) dfs1(v);
    dfsorder.push_back(u);
}

void dfs2(int u, int componts) {
    vis[u] = componts;
    for(auto v: rG[u])
        if(!vis[v]) dfs2(v, componts);
}

int kosaraju() {
    for(int u = 1; u <= n; u++)
        if(!vis[u]) dfs1(u);

    fill(vis, vis+maxn, 0);

    int componts = 0;
    for(int i = n-1; i >= 0; i--) {
        int u = dfsorder[i];
        if(!vis[u]) dfs2(u, ++componts);
    }
    return componts;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    cout << kosaraju() << endl;
    for(int u = 1; u <= n; u++)
        cout << vis[u] << (u == n ? "\n" : " ");


    return 0;
}
