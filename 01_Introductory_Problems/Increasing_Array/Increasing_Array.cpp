#include<cstdio>
#include<algorithm>
using namespace std;

int n, pre, tmp;
long long ans;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ans += max(0, pre - tmp);
        pre = max(pre, tmp);
    }
    printf("%lld\n", ans);

    return 0;
}
