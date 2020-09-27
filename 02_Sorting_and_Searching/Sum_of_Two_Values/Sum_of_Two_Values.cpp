#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, x, tmp;
vector<pair<int, int> > vec;

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        vec.push_back(make_pair(tmp, i+1));
    }

    sort(vec.begin(), vec.end());

    int l = 0, r = n - 1;
    while(l < r) {
        int t = vec[l].first + vec[r].first;
        if(t == x) {
            printf("%d %d\n", vec[l].second, vec[r].second);
            return 0;
        }
        else if(t < x) l++;
        else r--;
    }

    printf("IMPOSSIBLE\n");
    return 0;
}
