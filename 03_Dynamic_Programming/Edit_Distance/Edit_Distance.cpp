/*
 * Edit Distance - O(nm)
 *
 * dp[i][k] = minimum numbers of moves to change a[:i] to b[:k]
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 5000 + 5;
// vector<vector<int> > dp(maxn, vector<int>(maxn, 1e9));
int dp[maxn][maxn];

int main() {
    string a, b;
    cin >> a >> b;

    for(int i = 0; i <= (int)a.length(); i++) {
        for(int j = 0; j <= (int)b.length(); j++) {
            if(i || j) dp[i][j] = 1e9;
            if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1));
        }
    }

    cout << dp[a.length()][b.length()] << endl;

    return 0;
}
