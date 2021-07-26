#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int maxn = 15;
int n, nn, m;
int G[1<<14];
struct node {
    bool id;
    node *next;
};

node *head = new node{0, NULL};
node *tmp;

void dfs(int v, int u, const int x) {
    if(u != x && (v&(nn-1)) == (x&((nn-1)<<1))) {
        tmp->next = new node{(bool)(v&1), tmp->next};
        return;
    }
    m--;
    int nv = (v&(nn-1))<<1;

    if(G[v&(nn-1)]&2) {
        nv += 1;
        G[v&(nn-1)] = G[v&(nn-1)]&1;
    }
    else
        G[v&(nn-1)] = G[v&(nn-1)]&2;
    dfs(nv, v, x);
    tmp->next = new node{(bool)(v&1), tmp->next};
}

void Hierholzer() {
    int n_pos=0, n_nxt;
    node *pos = head;
    while(pos) {
        if(G[n_pos&(nn-1)]) {
            m--;
            tmp = pos;
            if(G[n_pos&(nn-1)]&2) {
                G[n_pos&(nn-1)] &= 1;
                n_nxt = ((n_pos & (nn-1))<<1)|1;
                dfs(n_nxt, n_pos, n_pos);
            } else {
                G[n_pos&(nn-1)] &= 2;
                n_nxt = (n_pos & (nn-1))<<1;
                dfs(n_nxt, n_pos, n_pos);
            }
            n_pos = n_nxt;
        }
        else {
            pos = pos->next;
            if(pos)
                n_pos = ((n_pos & (nn-1))<<1)|(pos->id);
        }
    }
}

int main() {
    cin >> n;
    nn = 1 << (n-1);
    m = 2*nn;
    fill(G, G+nn, 3);
    G[0] = 2;

    Hierholzer();

    node *pos = head->next;

    for(int i = 1; i < n; i++)
        cout << "0";

    while(pos) {
        cout << (pos->id ? "1" : "0");
        pos = pos->next;
    }
    cout << (n == 1 ? "" : "0") << endl;

    return 0;
}
