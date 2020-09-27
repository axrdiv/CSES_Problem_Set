#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int a[maxn], b[maxn];
int n, ans, np;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);

    sort(a, a + n);
    sort(b, b + n);

    int p1 = 0, p2 = 0;

    while(p1 < n && p2 < n) {
        if(a[p1] < b[p2]) {
            p1++; np++;
            ans = max(ans, np);
        }
        else {
            p2++; np--;
        }
    }

    printf("%d\n", ans);

    return 0;
}
