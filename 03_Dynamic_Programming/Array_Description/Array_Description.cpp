#include<cstdio>
#include<cstring>
using namespace std;
const int maxm = 100 + 5;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, ans;
int dp[2][maxm], vec[maxn];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);

    // init
    if(vec[0]) dp[0][vec[0]] = 1;
    else
        for(int i = 1; i <= m; i++) dp[0][i] = 1;

    for(int i = 1; i < n; i++) {
        memset(dp[i&1], 0, sizeof(int) * maxm);
        int st = 1, ed = m;
        if(vec[i]) {
            st = vec[i];
            ed = vec[i];
        }

        for(int j = st; j <= ed; j++) {
            for(int k = -1; k <= 1; k++) {
                dp[i&1][j] += dp[(i-1)&1][j+k];
                dp[i&1][j] %= mod;
            }
        }

    }

    for(int i = 1; i <= m; i++) {
        ans += dp[(n-1)&1][i];
        ans %= mod;
    }

    printf("%d\n", ans);

    return 0;
}
