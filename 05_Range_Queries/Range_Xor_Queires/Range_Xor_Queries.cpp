#include<iostream>
using namespace std;
const int maxn = 2*1e5 + 5;
int tree[maxn<<2];
int n, t, q;

void tset(int k, int x) {
    k += n;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2)
        tree[k] = tree[2*k] ^ tree[2*k+1];
}

int txor(int a, int b) {
    a += n; b += n;
    int s = 0;
    while(a <= b) {
        if(a%2 == 1) s ^= tree[a++];
        if(b%2 == 0) s ^= tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> t >> q;
    n = 1;
    while(n < t) n <<= 1;

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        tset(i, tmp);
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << txor(a, b) << endl;
    }

    return 0;
}
