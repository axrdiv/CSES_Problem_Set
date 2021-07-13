#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

int n, m;

bool vis[maxn];
long long dis[maxn][4];

vector<pair<int, int> > G[maxn];

void bellman() {
    for(int i = 1; i <= n; i++)
        dis[i][0] = INF;

    dis[1][0] = 0;
    dis[1][1] = 1;
    dis[1][2] = 0;
    dis[1][2] = 0;

    priority_queue<pair<long long, int> > q;
    q.push({0, 1});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : G[u]) {
            int v = e.first;
            int w = e.second;
            if(dis[v][0] == dis[u][0] + w) {
                dis[v][1] += dis[u][1];
                dis[v][1] %= MOD;

                dis[v][2] = min(dis[v][2], dis[u][2] + 1);
                dis[v][3] = max(dis[v][3], dis[u][3] + 1);
            }
            else if(dis[v][0] > dis[u][0] + w) {
                dis[v][0] = dis[u][0] + w;
                dis[v][1] = dis[u][1];
                dis[v][2] = dis[u][2] + 1;
                dis[v][3] = dis[u][3] + 1;
                q.push({-dis[v][0], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    bellman();

    for(int i = 0; i < 4; i++)
        cout << dis[n][i] << (i == 3 ? "\n" : " ");

    return 0;
}
