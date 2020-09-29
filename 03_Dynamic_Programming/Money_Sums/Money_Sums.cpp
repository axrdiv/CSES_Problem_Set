#include<cstdio>
using namespace std;

const int maxn = 100 + 5;
const int maxx = 1000 + 5;
int n, coin[maxn], cnt;
bool dp[maxn * maxx];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &coin[i]);

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 1e5; j >= coin[i]; j--) {
            dp[j] |= dp[j - coin[i]];
        }
    }

    for(int i = 1; i <= 1e5; i++) cnt += dp[i];
    printf("%d\n", cnt);

    for(int i = 1; i <= 1e5; i++)
        if(dp[i])
            printf("%d%c", i, (--cnt ? ' ' : '\n'));

    return 0;
}
