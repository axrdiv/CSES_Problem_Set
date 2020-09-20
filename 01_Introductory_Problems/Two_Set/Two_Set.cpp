#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
ll n, cnt;
bool set[maxn];


int main() {
    cin >> n;
    ll s = ((n + 1) * n) >> 1;
    if(s & 1) {
        cout << "NO" << endl;
        return 0;
    }

    s = s >> 1;
    for(int i = n; i > 0; i--) {
        if(s < i) continue;
        s -= i;
        set[i] = 1;
        cnt++;
        if(s == 0) break;
    }
    cout << "YES" << endl;
    cout << cnt << endl;
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        if(set[i]) {
            if(flag) cout << " ";
            cout << i;
            flag = 1;
        }
    }
    cout << endl << n - cnt << endl;
    flag = 0;
    for(int i = 1; i <= n; i++) {
        if(!set[i]) {
            if(flag) cout << " ";
            cout << i;
            flag = 1;
        }
    }
    cout << endl;

    return 0;
}
