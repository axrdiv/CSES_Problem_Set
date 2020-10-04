#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5 + 5;
vector<vector<int> > path(maxn);
int dis[maxn];
int n, m, a, b;

int bfs() {
    queue<int> que;
    que.push(0);
    dis[0] = 1;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        const int &d = dis[t];
        for(auto nt : path[t]) {
            if(dis[nt]) continue;
            que.push(nt);
            dis[nt] = d + 1;
            if(nt == n-1) return d + 1;
        }
    }
    return -1;
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int t = bfs();
    if(t < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << t << endl;
    int st = n - 1;
    vector<int> ans;
    ans.push_back(st + 1), t--;
    while(st != 0) {
        for(auto x : path[st]) {
            if(dis[x] == t) {
                ans.push_back(x + 1);
                t--, st = x;
                break;
            }
        }
    }


    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << (i == 0 ? '\n' : ' ');

    return 0;
}
