#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
int n, m;
vector<string> laby;
int vis[2][maxn][maxn];             // vis[0] is monster's, vis[1] is player's
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char ch[] = {'R', 'L', 'D', 'U'};

struct role {
    pair<int, int> p;
    bool m;
    role(pair<int, int> p, bool m) : p(p), m(m) {};
};

bool bfs(pair<int, int>& exitus) {
    pair<int, int> A;
    vector<pair<int, int> > monster;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(laby[i][j] == 'A') {
                A = make_pair(i, j);
                laby[i][j] = '.';
                vis[1][i][j] = 1;
            }
            else if(laby[i][j] == 'M') {
                monster.push_back(make_pair(i, j));
                laby[i][j] = '.';
                vis[0][i][j] = 1;
            }

    // Already on the side
    if((A.first == n - 1 || A.first == 0 || A.second == 0 || A.second == m - 1)) {
        exitus = A;
        return true;
    }

    queue<role> que;
    for(auto m : monster) que.push(role(m, false));
    que.push(role(A, true));

    while(!que.empty()) {
        role r = que.front(); que.pop();
        for(int d = 0; d < 4; d++) {
            int nx = r.p.first + dx[d];
            int ny = r.p.second + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && laby[nx][ny] == '.') {
                if(r.m && vis[1][nx][ny]) continue;
                if(vis[0][nx][ny]) continue;
                // player use vis[1], monster use vis[0];
                vis[r.m][nx][ny] = vis[r.m][r.p.first][r.p.second] + 1;
                que.push(role(make_pair(nx, ny), r.m));
                if(r.m && (nx == n - 1 || nx == 0 || ny == 0 || ny == m - 1)) {
                    exitus = make_pair(nx, ny);
                    return true;
                }
            }
        }
    }
    return 0;
}

void recall(pair<int, int> t) {
    vector<char> ans;
    while(vis[1][t.first][t.second] != 1) {
        for(int d = 0; d < 4; d++) {
            int nx = t.first + dx[d];
            int ny = t.second + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && laby[nx][ny] == '.') {
                if(vis[1][nx][ny] == vis[1][t.first][t.second] - 1) {
                    t = make_pair(nx, ny);
                    ans.push_back(ch[d]);
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;
}

int main() {
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i < n; i++) {
        getline(cin, tmp);
        laby.push_back(tmp);
    }

    pair<int, int> exitus;
    bool r = bfs(exitus);
    cout << (r ? "YES" : "NO") << endl;

    if(r) recall(exitus);

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vis[1][i][j] << (j == m - 1 ? '\n' : ' ');
        }
    }

    cout << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vis[0][i][j] << (j == m - 1 ? '\n' : ' ');
        }
    }
    */

    return 0;
}
