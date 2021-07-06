#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;

vector<int> G[maxn];
int n, m;

int vis[maxn];
vector<int> vec, ans;

bool dfs(int u) {
    vis[u] = 1;
    for(auto v : G[u]) {
        if(vis[v] == 1) {
            vec.push_back(v);
            return true;
        }
        if(vis[v]) continue;
        if(dfs(v)) {
            vec.push_back(v);
            return true;
        }
    }
    vis[u] = 2;
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
            vec.push_back(st);
            ans.push_back(*vec.begin());
            for(int i = 1; i < vec.size(); i++) {
                ans.push_back(vec[i]);
                if(vec[i] == *vec.begin()) break;
            }

            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++)
                cout << ans[ans.size()-1-i] << (i == ans.size()-1 ? "\n" : " ");
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
