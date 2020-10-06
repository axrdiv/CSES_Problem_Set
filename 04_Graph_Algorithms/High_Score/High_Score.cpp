/*
 * Use Bellman-Ford Algorithm and DFS
 * If graph contains a negative cycle, the algorithm can detect this.
 * Then use DFS to expand negative array
 */
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
const int maxn = 2500 + 5;
const long long INF = 1e14 + 5;
int n, m;
long long dis[maxn];
int negative[maxn];
int vis[maxn];


vector<tuple<int, int, int> > edge;
vector<vector<int> > G(maxn);

void dfs(int u, int* arr) {
    arr[u] = 2;
    for(auto v : G[u]) {
        if(arr[v] != 2)
            dfs(v, arr);
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge.push_back(make_tuple(a, b, -c));
        G[a].push_back(b);
    }

    // init
    for(int i = 0; i < n; i++)
        dis[i] = INF;

    dis[0] = 0;
    for(int i = 0; i < n; i++) {
        for(auto e : edge) {
            int a, b, w;
            tie(a, b, w) = e;
            dis[b] = min(dis[b], dis[a] + w);
        }
    }

    dfs(0, vis);

    for(auto e : edge) {
        int a, b, w;
        tie(a, b, w) = e;
        if(dis[b] > dis[a] + w)
            negative[b] = 1;
        dis[b] = min(dis[b], dis[a] + w);
    }

    for(int i = 0; i < n; i++) {
        if(vis[i] && negative[i] == 1) dfs(i, negative);
    }

    cout << (negative[n-1] ? -1 : -dis[n-1]) << endl;

    return 0;
}
