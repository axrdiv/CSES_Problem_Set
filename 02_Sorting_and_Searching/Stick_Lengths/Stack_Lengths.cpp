#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n;
int vec[maxn];
long long ans;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &vec[i]);
    nth_element(vec, vec + n/2, vec+n);
    for(int i = 0; i < n; i++) ans += abs(vec[i] - vec[n>>1]);
    printf("%lld\n", ans);

    return 0;
}
