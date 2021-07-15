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

bool fromutov(int u, int v) {
    if(u == v) return true;

    vis[u] = 1;
    for(auto e : G[u])
        if(!vis[e] && fromutov(e, v)) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    int componts = kosaraju();

    // for(int i = 1; i <= n; i++)
    //     cout << vis[i] << (i == n ? "\n" : " ");


    if(componts == 1) cout << "YES" << endl;
    else {
        cout << "NO" << endl;

        int u;
        for(u = 1; u < n; u++)
            if(vis[u] != vis[u+1]) break;

        int v = u + 1;
        fill(vis, vis + maxn, 0);
        if(fromutov(u, v)) swap(u, v);
        cout << u << " " << v << endl;
    }


    return 0;
}
