/*
 * Bellman-Ford     - O(mn)
 * Dijkstra         - O(n + mlogm)
 * Floyd-Warshall   - O(n^3)
 *
 * So use Dijkstra's algorithm
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e15 + 5;
vector<vector<pair<int, int> > > G(maxn);
int n, m;
int a, b, c;
long long dis[maxn];
bool vis[maxn];

void dijkstra() {
    priority_queue<pair<long long, int> > q;
    for(int i = 0; i < n; i++)
        dis[i] = INF;

    dis[0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u : G[a]) {
            int b = u.first, w = u.second;
            if(dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(make_pair(b, c));
    }

    dijkstra();

    for(int i = 0; i < n; i++)
        cout << dis[i] << (i == n-1 ? '\n' : ' ');

    return 0;
}
