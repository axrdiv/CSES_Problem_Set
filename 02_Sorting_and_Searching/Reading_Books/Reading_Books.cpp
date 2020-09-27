#include<cstdio>
#include<algorithm>
using namespace std;
int n, tmp;
long long ans, t;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ans += tmp;
        t = max(t, (long long)tmp);
    }

    printf("%lld\n", max(ans, 2 * t));

    return 0;
}
