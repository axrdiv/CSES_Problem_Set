#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 2e5+5;
int n, m;
vector<pair<int, long long> > G[maxn];
int link[maxn], siz[maxn];
bool vis[maxn];

int find(int x) {
    if(x == link[x]) return x;
    return link[x] = find(link[x]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if(siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    link[b] = a;
}

long long kruskal() {
    long long ans = 0;
    for(int i = 0; i <= n; i++) link[i] = i;
    for(int i = 0; i <= n; i++) siz[i] = 1;

    priority_queue<pair<long long, pair<int, int> > > q;
    q.push({0, {1, 0}});
    while(!q.empty()) {
        int u = q.top().second.first;
        long long w = -q.top().first;
        // cout << u << " " << q.top().second.second << " " << -q.top().first << endl;
        q.pop();
        if(!vis[u] && !same(0, u)) {
            vis[u] = true;
            uni(0, u);
            ans += w;
            for(auto e : G[u]) {
                if(!vis[e.first]) {
                    // cout << "input " << u << " " << e.first << " " << -e.second << endl;
                    q.push({-e.second, {e.first, u}});
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    long long ans = kruskal();
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}
