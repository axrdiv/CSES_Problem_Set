#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<tuple>
using namespace std;
/* 
 * first: depth
 * second: id
 */
typedef pair<int, int> info;

const int maxn = 2e5 + 5;
const info maxx = {1e9+5, 1e9+5};
int n, q, N;
int a, b;
vector<int> adj[maxn];
int id2pos[maxn];
vector<info> vett;

void ETT(int s, int e, int d) {
    if(s > 1 && !id2pos[s]) id2pos[s] = vett.size();
    vett.push_back({d, s});
    for(auto u : adj[s]) {
        if(u == e) continue;
        ETT(u, s, d+1);
        vett.push_back({d, s});
    }
}

void tset(int k, const info& x, vector<info>& tree) {
    k += N;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

info tmin(int a, int b, vector<info>& tree) {
    a += N, b += N;
    info s = maxx;
    while(a <= b) {
        if(a%2 == 1) s = min(s, tree[a++]);
        if(b%2 == 0) s = min(s, tree[b--]);
        a /= 2, b /= 2;
    }
    return s;
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int t;
        cin >> t;
        adj[t].push_back(i);
    }

    ETT(1, 0, 0);
    vector<info> tree(vett.size()<<2, maxx);

    N = 1;
    while(N < vett.size()) N <<= 1;

    for(int i = 0; i < vett.size(); i++)
        tset(i, vett[i], tree);

    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        a = id2pos[a];
        b = id2pos[b];
        if(a > b) swap(a, b);
        cout << tmin(a, b, tree).second << endl;
    }

    return 0;
}
