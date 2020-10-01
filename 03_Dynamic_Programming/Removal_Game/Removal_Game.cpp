#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 5000 + 5;

int n;
long long vec[maxn], dp[maxn][maxn][2];
long long acc[maxn];

long long dfs(int st, int ed, bool p) {
    if(dp[st][ed][p]) return dp[st][ed][p];
    if(st == ed) return 0;
    if(st + 1 == ed) return dp[st][ed][p] = vec[st];

    long long tot = acc[ed] - acc[st];
    dp[st][ed][p] = tot - min(dfs(st + 1, ed, !p), dfs(st, ed - 1, !p));
    return dp[st][ed][p];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &vec[i]);
        acc[i + 1] = acc[i] + vec[i];
    }

    printf("%lld\n", dfs(0, n, 0));

    return 0;
}
