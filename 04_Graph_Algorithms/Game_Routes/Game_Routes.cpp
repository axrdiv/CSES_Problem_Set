#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> G[maxn];
vector<int> rG[maxn];
int vis[maxn];
stack<int> seq;
int dis[maxn];

bool topological_sorting(int u) {
    if(vis[u] == 1) return true;
    vis[u] = 1;
    for(auto v : G[u]) {
        if(vis[v] != 2 && topological_sorting(v)) return true;
    }
    vis[u] = 2;
    seq.push(u);
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

    topological_sorting(1);
    seq.pop();
    dis[1] = 1;
    while(!seq.empty()) {
        int u = seq.top(); seq.pop();
        for(auto v : rG[u]) {
            dis[u] += dis[v];
            dis[u] %= MOD;
        }
    }

    cout << dis[n] << endl;

    return 0;
}
