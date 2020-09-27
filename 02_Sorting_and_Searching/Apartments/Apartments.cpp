#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, m, k;
int app[maxn], size[maxn], ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%d", &app[i]);
    for(int i = 0; i < m; i++) scanf("%d", &size[i]);

    sort(app, app + n);
    sort(size, size + m);

    int p1 = 0, p2 = 0;
    while(p1 < n && p2 < m) {
        if(app[p1] < size[p2] - k) p1++;
        else if(app[p1] > size[p2] + k) p2++;
        else {
            ans++;
            p1++;
            p2++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
