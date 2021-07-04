#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 20 + 1;
int n, x, tmp;
vector<int> weights;

pair<int, int> best[1<<maxn];

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        weights.push_back(tmp);
    }

    best[0] = {0, x};
    for(int s = 1; s < (1<<n); s++) {
        best[s] = {n+1, 0};
        for(int p = 0; p < n; p++) {
            if(s & (1<<p)) {
                auto option = best[s^(1<<p)];
                if(option.second + weights[p] <= x) {
                    option.second += weights[p];
                }
                else {
                    option.first++;
                    option.second = weights[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }

    cout << best[(1<<n)-1].first << endl;
    return 0;
}
