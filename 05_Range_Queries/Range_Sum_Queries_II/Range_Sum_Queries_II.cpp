#include<iostream>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int t, n, q;
long long tree[maxn << 2];

void tadd(int k, int x) {
    k += n;
    tree[k] += x;
    for(k /= 2; k >= 1; k /= 2)
        tree[k] += x;
}

long long tsum(int a, int b) {
    a += n; b += n;
    long long s = 0;
    while(a <= b) {
        if(a%2 == 1) s += tree[a++];
        if(b%2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> t >> q;
    n = 1;
    while(n < t) n = n<<1;

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        tadd(i, tmp);
    }

    /*
    for(int i = 0; i < 2 * n; i++)
        cout << tree[i] << " ";
    cout << endl;
    */

    for(int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1)
            tadd(b, c-tree[n+b]);
        else
            cout << tsum(b, c-1) << endl;
    }

    return 0;
}
