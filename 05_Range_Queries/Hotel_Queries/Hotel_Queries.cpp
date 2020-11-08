#include<iostream>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int t, n, m;
int tree[maxn << 2];

void tset(int k, int x) {
    k += n;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2)
        tree[k] = max(tree[2*k], tree[2*k+1]);
}

int tmax(int a, int b) {
    a += n; b += n;
    int s = 0;
    while(a <= b) {
        if(a%2 == 1) s = max(s, tree[a++]);
        if(b%2 == 0) s = max(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> t >> m;
    n = 1;
    while(n < t) n <<= 1;

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        tset(i, tmp);
    }

    for(int i = 0; i < m; i++) {
        int q;
        cin >> q;

        int l = 0, r = t;
        while(l < r) {
            int mid = (l + r) / 2;
            if(tmax(l, mid) < q) l = mid + 1;
            else r = mid;
        }
        if(l < t) {
            cout << l + 1 << (i == m-1 ? '\n' : ' ');
            tset(l, tree[l+n] - q);
        }
        else
            cout << 0 << (i == m-1 ? '\n' : ' ');
    }

    return 0;
}
