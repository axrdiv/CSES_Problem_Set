#include<iostream>
#include<string>
using namespace std;
const int maxn = 10;
bool vis[maxn][maxn];
int ans;
string path;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char dc[] = {'U', 'R', 'D', 'L'};

void dfs(int x, int y, int dep, int n) {
    if(dep == n * n) {
        if(x == n && y == 1) ans++;
        return;
    }
    for(int d = 0; d < 4; d++) {
        if(path[dep - 1] != '?' && path[dep - 1] != dc[d]) continue;

        int nx = x + dx[d];
        int ny = y + dy[d];
        if(dep != n * n - 1 && nx == n && ny == 1) continue;
        if(!vis[nx][ny]) {
            if(vis[nx + dx[d]][ny + dy[d]] && 
              !vis[nx + dx[(d+5)%4]][ny + dy[(d+5)%4]] && 
              !vis[nx + dx[(d+3)%4]][ny + dy[(d+3)%4]])
                continue;
            vis[nx][ny] = 1;
            dfs(nx, ny, dep + 1, n);
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> path;

    for(int i = 0; i <= 8; i++)
        vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = 1;

    vis[1][1] = 1;
    dfs(1, 1, 1, 7);
    cout << ans << endl;

}
