#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500 + 5;

int a, b;
int dp[maxn][maxn];

int dfs(int a, int b) {
    if(a == 0 || b == 0) return 0;
    if(a == b) return 0;
    if(a > b) swap(a, b);
    if(dp[a][b]) return dp[a][b];

    dp[a][b] = a * b;
    for(int i = 1; i <= a / 2; i++) {
        dp[a][b] = min(dp[a][b], dfs(i, b) + dfs(a - i, b) + 1);
    }

    for(int i = 1; i <= b / 2; i++) {
        dp[a][b] = min(dp[a][b], dfs(a, i) + dfs(a, b - i) + 1);
    }

    return dp[a][b];
}

int main() {
    cin >> a >> b;
    cout << dfs(a, b) << endl;
    return 0;
}
