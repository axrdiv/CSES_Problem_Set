#include<iostream>
using namespace std;
typedef long long ll;
int n, x, y;

long long solve(int x, int y) {
    ll m = (ll)max(x, y);
    ll base = m * m;
    if(m & 1)
        base -= (x - 1) + (m - y);
    else
        base -= (y - 1) + (m - x);
    return base;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }


    return 0;
}
