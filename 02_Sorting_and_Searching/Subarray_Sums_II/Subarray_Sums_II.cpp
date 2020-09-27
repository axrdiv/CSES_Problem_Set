#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, x;
int vec[maxn];
vector<pair<long long, int> > acc;
long long ans;

int main() {
    scanf("%d%d", &n, &x);
    acc.push_back(make_pair(0, 0));

    for(int i = 1; i <= n; i++) {
        scanf("%d", &vec[i]);
        acc.push_back(make_pair(acc[i-1].first + vec[i], i));
    }

    sort(acc.begin(), acc.end());

    for(int st = 0; st < n; st++) {
        long long t = x + acc[st].first;
        vector<pair<long long, int> >::iterator it1 = upper_bound(acc.begin(), acc.end(), make_pair(t, acc[st].second));
        vector<pair<long long, int> >::iterator it2 = lower_bound(acc.begin(), acc.end(), make_pair(t+1, 0));
        ans += it2 - it1;
    }

    printf("%lld\n", ans);

    return 0;
}
