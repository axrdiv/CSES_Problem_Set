#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
const int maxx = 1e5 + 5;

int n, x, ans;
int h[maxn], s[maxn];
int dp[maxx];

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);


    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= 0; j--) {
            if(j - h[i] >= 0 && (j - h[i] == 0 || dp[j - h[i]]))
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    for(int i = 0; i <= x; i++) ans = max(ans, dp[i]);

    printf("%d\n", ans);

    return 0;
}
