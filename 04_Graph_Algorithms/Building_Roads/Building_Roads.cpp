#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a, b;
int color[maxn];
vector<vector<int> > path(maxn);
vector<int> link;


void dfs(int st, const int &c) {
    color[st] = c;
    for(auto nt : path[st]) {
        if(!color[nt]) dfs(nt, c);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(!color[i]) {
            dfs(i, ++c);
            link.push_back(i);
        }
    }

    cout << c - 1 << endl;
    for(int i = 0; i < link.size() - 1; i++) {
        cout << link[i] + 1 << " " << link[i + 1] + 1 << endl;
    }

    return 0;
}
