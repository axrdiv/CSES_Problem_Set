#include<iostream>
using namespace std;
const int maxn = 2*1e5 + 5;
const int maxx = 1e9 + 5;
int n, q, t;
int tree[maxn << 2];

void tset(int k, int x) {
    k += n;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2)
        tree[k] = min(tree[2*k], tree[2*k+1]);
}

int tmin(int a, int b) {
    a += n; b += n;
    int s = maxx;
    while(a <= b) {
        if(a%2 == 1) s = min(s, tree[a++]);
        if(b%2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> t >> q;
    n = 1;
    while(n < t) n <<= 1;

    for(int i = 1; i < 2*n; i++)
        tree[i] = maxx;

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        tset(i, tmp);
    }

    for(int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1)
            tset(b, c);
        else
            cout << tmin(b, c-1) << endl;
    }

    return 0;
}
