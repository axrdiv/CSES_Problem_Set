#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
vector<int> G[maxn], ans;
int vis[maxn];

bool dfs(int u) {
    vis[u] = 1;
    for(auto v : G[u]) {
        if(vis[v] == 1) return true;
        if(vis[v] == 2) continue;
        if(dfs(v)) return true;
    }
    vis[u] = 2;
    ans.push_back(u);
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    for(int st = 1; st <= n; st++) {
        if(!vis[st] && dfs(st)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << (i ? " " : "\n");

    return 0;
}
