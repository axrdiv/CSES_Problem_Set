#include<iostream>
#include<vector>
using namespace std;
const int maxn = 2 * 1e5 + 5;
vector<int> adj[maxn];
int n, a, b;
int maxd, id;

void dfs(int s, int e, int d) {
    if(d > maxd) {
        maxd = d;
        id = s;
    }
    for(auto u : adj[s]) {
        if(u == e) continue;
        dfs(u, s, d+1);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);
    int st = id;
    maxd = 0;
    dfs(st, 0, 0);

    cout << maxd << endl;

    return 0;
}
