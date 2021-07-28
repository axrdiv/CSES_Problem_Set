/*
 * Warnsdorf’s rule is a simple and effective heuristic for finding a knight’s tour.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 8;
int vis[maxn][maxn];
int x, y;
const int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int possible(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < maxn && ny >= 0 && ny < maxn && !vis[nx][ny]) {
            cnt++;
        }
    }
    return cnt;
}

bool dfs(int x, int y, int d) {
    vis[x][y] = d;
    if(d == 64) return true;
    priority_queue<pair<int, pair<int, int> > > que;

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < maxn && ny >= 0 && ny < maxn && !vis[nx][ny]) {
            que.push({-possible(nx, ny), {nx, ny}});
        }
    }

    while(!que.empty()) {
        auto t = que.top(); que.pop();
        int nx = t.second.first;
        int ny = t.second.second;

        if(dfs(nx, ny, d+1)) return true;
    }

    vis[x][y] = 0;
    return false;
}


int main() {
    cin >> x >> y;
    x--, y--;
    dfs(x, y, 1);

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            cout << vis[j][i] << (j == maxn-1 ? "\n" : " ");

    return 0;
}
