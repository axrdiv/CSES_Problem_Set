#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, m;
vector<string> rooms;
int cnt;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    rooms[x][y] = '#';
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string st;
        cin >> st;
        rooms.push_back(st);
    }

    // for(int i = 0 ; i < n; i++)
    //     cout << rooms[i] << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rooms[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
