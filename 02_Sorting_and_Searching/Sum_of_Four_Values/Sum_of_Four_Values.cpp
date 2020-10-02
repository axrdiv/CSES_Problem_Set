#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
vector<int> vec;
int n, x;
vector<tuple<int, int, int> > tv;

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        vec.push_back(tmp);
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            tv.push_back(make_tuple(vec[i] + vec[j], i, j));

    sort(tv.begin(), tv.end());

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int re = x - vec[i] - vec[j];
            auto it = lower_bound(tv.begin(), tv.end(), make_tuple(re, j + 1, 0));
            if(get<0>(*it) == re) {
                cout << i+1 << " " << j+1 << " " << get<1>(*it)+1 << " " << get<2>(*it)+1 << endl;
                return 0;
            }

        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
