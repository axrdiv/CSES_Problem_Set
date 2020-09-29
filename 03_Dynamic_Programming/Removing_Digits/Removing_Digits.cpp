#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 5;

int dp[maxn];
int n;

int dfs(int t) {
    if(t == 0) return dp[0];
    if(dp[t]) return dp[t];

    int d = t;
    dp[t] = t;
    while(d) {
        dp[t] = min(dp[t], dfs(t - (d % 10)) + 1);
        d /= 10;
    }
    return dp[t];
}

int main() {
    scanf("%d", &n);
    printf("%d\n", dfs(n));

    return 0;
}
