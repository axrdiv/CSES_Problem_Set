#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
vector<int> rG[maxn];
int n, m;
long long dis[maxn];
bool vis[maxn];
int prv[maxn];

void bfs() {
    priority_queue<tuple<long long, int, int> > q;
    q.push({1, n, 0});
    while(!q.empty()) {
        long long l;
        int v, vb;
        tie(l, v, vb) = q.top();
        q.pop();
        if(l <= dis[v]) continue;
        dis[v] = l;
        prv[v] = vb;

        for(auto e : rG[v]) {
            if(l + 1 > dis[e]) {
                q.push({l+1, e, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    bfs();

    if(!dis[1]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    int p = 1;
    while(p) {
        ans.push_back(p);
        p = prv[p];
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i != ans.size()-1 ? " " : "\n");

    return 0;
}
