/*
 * use Floyd-Warshall's algorithm   - O(n^3)
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500 + 5;
const long long INF = 1e15 + 5;
long long dis[maxn][maxn];
int n, m, q;
int a, b, c;

void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dis[i][j] = (i == j ? 0 : INF);
}

void floyd_warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;

    init();
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        if(dis[a][b]) {
            dis[a][b] = min(dis[a][b], (long long)c);
            dis[b][a] = min(dis[b][a], (long long)c);
        }
    }

    floyd_warshall();

    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        a--, b--;
        cout << (dis[a][b] >= INF ? -1 : dis[a][b]) << endl;
    }



    return 0;
}
