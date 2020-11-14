#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 2e5 + 5;
int n, q;
int tsucc[20][maxn], dep[maxn];
int a, b;

int succ(int x, int l) {
    if(l==0 || tsucc[l][x]) return tsucc[l][x];
    return tsucc[l][x] = succ(succ(x, l-1), l-1);
}

int qsucc(int x, int k, int l) {
    if((1<<l) < k)
        x = qsucc(x, k, l+1);

    if((1<<l) & k)
        x = succ(x, l);

    return x;
}

int main() {
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        cin >> tsucc[0][i];
        dep[i] = dep[tsucc[0][i]]+1;
    }

    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        if(dep[a] > dep[b]) swap(a, b);
        b = qsucc(b, dep[b]-dep[a], 0);
        while(a != b) {
            a = tsucc[0][a];
            b = tsucc[0][b];
        }
        cout << a << endl;
    }

    return 0;
}
