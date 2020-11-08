#include<iostream>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, t;
int tree[maxn << 2];
int vec[maxn];

void tadd(int k, int x) {
    k += n;
    tree[k] += x;
    for(k /= 2; k >= 1; k /= 2)
        tree[k] = tree[2*k] + tree[2*k+1];
}

int tsum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while(a <= b) {
        if(a%2 == 1) s += tree[a++];
        if(b%2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> t;
    n = 1;
    while(n < t) n <<= 1;

    for(int i = 0; i < t; i++) {
        cin >> vec[i];
        tadd(i, 1);
    }

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        int l = 0, r = t - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(tsum(0, mid) < tmp) l = mid + 1;
            else r = mid;
        }
        cout << vec[l] << (i == t-1 ? '\n' : ' ');
        tadd(l, -1);
        /*
        for(int j = 0; j < t; j++)
            cout << tree[j+n] << (j == t-1 ? '\n' : ' ');
        */
    }

    return 0;
}
