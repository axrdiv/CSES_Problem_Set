#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a, b;
vector<vector<int> > G(maxn);
int vis[maxn];
vector<int> ans;
int d;

bool dfs(int u, int dep) {
    vis[u] = dep;
    d = max(d, dep);
    for(auto v : G[u]) {
        if(vis[v] && vis[u] - vis[v] >= 2) {
            ans.push_back(v);
            return true;
        }
        if(!vis[v]) {
            if(dfs(v, dep + 1)) {
                if(ans.size() < 2 || ans.front() != ans.back())
                    ans.push_back(v);
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool t = false;
    int dep = 1;
    for(int v = 0; v < n; v++) {
        if(!vis[v])
            if(t = dfs(v, d + 3))
                break;
    }
    if(!t) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if(ans.front() != ans.back()) ans.push_back(ans[0]);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << (i == ans.size()-1 ? '\n' : ' ');

    return 0;
}
