#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const long long maxk = 1e18;
int n;
long long k;
vector<pair<long long, int> > len;

int main() {
    cin >> n;

    len.push_back(make_pair((long long)0, 0));
    len.push_back(make_pair((long long)9, 1));
    long long base = 10;

    while(len.back().first < maxk) {
        long long tmp = len.back().first + base * (len.back().second+1) * 9;
        base *= 10;
        len.push_back(make_pair(tmp, len.back().second + 1));
    }


    for(int i = 0; i < n; i++) {
        cin >> k;
        auto p = lower_bound(len.begin(), len.end(), make_pair((long long)k, 0));
        base = 1;
        int j = 0;
        while(j++ < (p-1)->second) base *= 10;

        long long num = ((k-1) -  (p-1)->first) / p->second + base;
        // cout << num << " " << ((k-1)-(p-1)->first)%(p->second) << endl;
        cout << to_string(num)[((k-1)-(p-1)->first)%(p->second)] << endl;

    }


    return 0;
}
