/*
 * Eulerian Paths / Eulerian Circuit
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 1e5+5;
int n, m;
set<int> G[maxn];
vector<int> Paths[maxn];

struct node {
    int id;
    node *next;
};
node *head = new node{1, NULL};
node *tmp;

void dfs(int v, int u, const int x) {
    if(u != x && v == x) {
        tmp->next = new node{v, tmp->next};
        return;
    }

    int nv = *G[v].begin();
    G[v].erase(nv);
    G[nv].erase(v);
    m--;
    dfs(nv, v, x);
    // cout << u << "->" << v << endl;
    tmp->next = new node{v, tmp->next};
}

void Hierholzer() {
    node *pos = head;
    while(pos) {
        int &u = pos->id;
        if(G[u].size()) {
            int v = *G[u].begin();
            tmp = pos;
            G[u].erase(v);
            G[v].erase(u);
            m--;
            dfs(v, u, u);
        } else
            pos = pos->next;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    // the degree of each node is even
    for(int u = 1; u <= n; u++) {
        if(G[u].size() & 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    Hierholzer();

    if(m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    node *pos = head;
    while(pos)
        cout << pos->id << ((pos = pos->next) ? " " : "\n");

    return 0;
}
