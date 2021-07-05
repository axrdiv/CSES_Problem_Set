#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 2e5 + 5;
const long long INF = 1e18;
vector<pair<int, int> > G[maxn];
int n, m;
priority_queue<pair<long long, int> > q;
long long dis[maxn], nodis[maxn];
bool processed[maxn];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
    }

    for(int i = 1; i <= n; i++) {
        nodis[i] = INF;
        dis[i] = INF;
    }

    nodis[1] = 0;
    q.push({0, 1});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u : G[a]) {
            int b = u.first, w = u.second;
            if(nodis[a] + w < nodis[b]) {
                nodis[b] = nodis[a] + w;
                q.push({-nodis[b], b});
            }
        }
    }

    fill(processed, processed+maxn, 0);
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u : G[a]) {
            int b = u.first, w = u.second;
            if(nodis[a] + w/2 < dis[b] || dis[a] + w < dis[b]) {
                dis[b] = min(nodis[a] + w/2, dis[a] + w);
                q.push({-dis[b], b});
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << nodis[i] << " " << dis[i] << endl;
    // }

    cout << dis[n] << endl;

    return 0;
}
