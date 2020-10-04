#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char pa[] = {'R', 'L' , 'D', 'U'};    // reversed

int path[maxn][maxn];
vector<string> laby;
vector<char> ans;
int n, m;

int bfs(int x, int y, int& bx, int& by) {
    queue<tuple<int, int, int> > que;
    que.push(make_tuple(x, y, 1));
    path[x][y] = 1;
    while(!que.empty()) {
        int a, b, c;
        tie(a, b, c) = que.front(); que.pop();
        for(int d = 0; d < 4; d++) {
            int nx = a + dx[d];
            int ny = b + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(laby[nx][ny] != '#' && !path[nx][ny]) {
                    path[nx][ny] = c + 1;
                    que.push(make_tuple(nx, ny, c+1));
                    if(laby[nx][ny] == 'B') {
                        bx = nx, by = ny;
                        return path[nx][ny];
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    string tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        laby.push_back(tmp);
    }

    int bx, by;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(laby[i][j] == 'A') {
                if(int p = bfs(i, j, bx, by)) {
                    cout << "YES" << endl;
                    cout << --p << endl;
                    int c = path[bx][by];
                    while(p--) {
                        for(int d = 0; d < 4; d++) {
                            int nx = bx + dx[d];
                            int ny = by + dy[d];
                            if(path[nx][ny] == c - 1) {
                                ans.push_back(pa[d]);
                                bx = nx, by = ny, c = c-1;
                                break;
                            }
                        }
                    }
                    reverse(ans.begin(), ans.end());
                    for(int i = 0; i < (int)ans.size(); i++) {
                        cout << ans[i];
                    }
                    cout << endl;
                } else {
                    cout << "NO" << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}
