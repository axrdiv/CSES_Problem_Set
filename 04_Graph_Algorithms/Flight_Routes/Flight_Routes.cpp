#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const long long INF = 1e18;
int n, m, k;
vector<pair<int, int> > G[maxn];
multiset<long long> s;
int vis[maxn];

void bfs(int st, int ed) {
    priority_queue<pair<long long, int> > q;
    q.push({0, st});
    fill(vis, vis+maxn, k);
    while(!q.empty() && (s.size() < k || -q.top().first <= *s.rbegin())) {
        int u = q.top().second;
        long long l = q.top().first;
        q.pop();
        if(!vis[u]) continue;
        vis[u]--;


        if(u == ed && (s.size() < k || -l <= *s.rbegin())) {
            if(s.size() == k)
                s.erase(prev(s.end()));
            s.insert(-l);
        }

        for(auto e : G[u]) {
            q.push({l-e.second, e.first});
        }
    }
}


int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
    }

    bfs(1, n);

    for(auto e : s)
        cout << e << (--k ? " " : "\n");

    return 0;
}
