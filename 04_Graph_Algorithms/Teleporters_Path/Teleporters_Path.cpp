#include<iostream>
#include<set>
using namespace std;
const int maxn = 1e5+5;
set<int> G[maxn];
set<int> E[maxn];
int n, m;

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
    m--;
    dfs(nv, v, x);
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
            m--;
            dfs(v, u, u);
        } else
            pos = pos->next;
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].insert(b);
        E[b].insert(a);
    }
    G[n].insert(1);
    E[1].insert(n);
    m++;

    for(int u = 1; u <= n; u++) {
        if(G[u].size() != E[u].size()) {
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
    bool flag = false;
    while(pos) {
        if(flag) cout << pos->id << " ";
        if(!flag && pos->id == n && pos->next->id == 1) flag = true;
        pos = pos->next;
    }

    pos = head->next;
    while(pos) {
        cout << pos->id << " ";
        if(pos->id == n && pos->next->id == 1) break;
        pos = pos->next;
    }
    cout << endl;


    return 0;
}
