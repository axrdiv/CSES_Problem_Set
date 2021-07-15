#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e5+5;
const int maxm = 2e5+5;
int n, m, maxsize = 1;
int link[maxn], siz[maxn];

int find(int x) {
    if(link[x] == x) return x;
    return link[x] = find(link[x]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}

int unin(int a, int b) {
    a = find(a);
    b = find(b);
    if(siz[a] < siz[b]) swap(a, b);
    link[b] = a;
    siz[a] += siz[b];
    return siz[a];
}


int main() {
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) link[i] = i;
    for(int i = 1; i <= n; i++) siz[i] = 1;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(!same(a, b)) {
            maxsize = max(maxsize, unin(a, b));
            n--;
        }
        cout << n << " " << maxsize << endl;
    }


    return 0;
}
