#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, x, tmp;
vector<pair<int, int> > vec;

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        vec.push_back(make_pair(tmp, i));
    }

    sort(vec.begin(), vec.end());

    for(int p = 0; p < n; p++) {
        int t = x - vec[p].first;
        int l = 0, r = n - 1;
        while(l < r) {
            if(l == p) l++;
            if(r == p) r--;

            if(vec[l].first + vec[r].first < t) l++;
            else if(vec[l].first + vec[r].first > t) r--;
            else {
                printf("%d %d %d\n", vec[p].second, vec[l].second, vec[r].second);
                return 0;
            }
        }
    }

    printf("IMPOSSIBLE\n");

    return 0;
}
