#include<iostream>
using namespace std;
const int maxn = 2e5 + 5;
int tsucc[20][maxn];
int n, q;

int x, k;

int succ(int x, int l) {
    if(x == 0) return 0;
    if(tsucc[l][x]) return tsucc[l][x];
    if(l == 0) return tsucc[l][x];
    return tsucc[l][x] = succ(succ(x, l-1), l-1);
}

int qsucc(int x, int k, int l) {
    if(x == 0) return 0;
    if((1<<l) > k) return x;
    x = qsucc(x, k, l+1);
    if((1<<l) & k) {
        return succ(x, l);
    }
    else
        return x;
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
        cin >> tsucc[0][i];

    for(int i = 0; i < q; i++) {
        cin >> x >> k;
        x = qsucc(x, k, 0);
        cout << (x ? x : -1)<< endl;
    }

    return 0;
}
