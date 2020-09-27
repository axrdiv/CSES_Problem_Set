#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int> > vec;
int n, a, b;
long long ans, t;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++) {
        t += vec[i].first;
        ans += vec[i].second - t;
    }

    printf("%lld\n", ans);

    return 0;
}
