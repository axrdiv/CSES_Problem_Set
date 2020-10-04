#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<vector<int> > G(maxn);
int set[maxn];
int n, m, a, b;

int dfs(int p, int c) {
    set[p] = c;
    for(auto x : G[p]) {
        if(set[x] == c) return true;
        if(set[x] == 0)
            if(dfs(x, -c))
                return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(set[i] == 0) {
            if(dfs(i, 1)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << (set[i] == -1 ? 2 : 1) << (i == n-1 ? '\n' : ' ');


    return 0;
}
