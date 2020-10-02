#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, x, p[maxn];

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);

    sort(p, p + n);

    int cnt = 0;
    int l = 0, r = n-1;
    while(l <= r) {
        if(p[l] + p[r] <= x) l++;
        r--;
        cnt++;
    }


    printf("%d\n", cnt);

    return 0;
}
