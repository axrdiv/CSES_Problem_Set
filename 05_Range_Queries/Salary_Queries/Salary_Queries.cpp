#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int t, n, q;
vector<int> salery, disc;
vector<tuple<char, int, int> > ques;
int tree[maxn<<4];

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
    cin >> t >> q;

    for(int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        salery.push_back(tmp);
        disc.push_back(tmp);
    }

    for(int i = 0; i < q; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        ques.push_back(make_tuple(a, b, c));
        if(a == '!') disc.push_back(c);
    }
    disc.push_back(0);
    disc.push_back(1e9+5);

    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());

    n = 1;
    while(n < disc.size()) n <<= 1;

    for(int i = 0; i < salery.size(); i++) {
        int k = lower_bound(disc.begin(), disc.end(), salery[i]) - disc.begin();
        tadd(k, 1);
    }

    for(int i = 0; i < ques.size(); i++) {
        char a;
        int b, c;
        tie(a, b, c) = ques[i];
        if(a == '!') {
            int k = lower_bound(disc.begin(), disc.end(), salery[b-1]) - disc.begin();
            tadd(k, -1);
            int kx = lower_bound(disc.begin(), disc.end(), c) - disc.begin();
            tadd(kx, 1);
            salery[b-1] = c;
        }
        else {
            int ka = lower_bound(disc.begin(), disc.end(), b) - disc.begin();
            int kb = upper_bound(disc.begin(), disc.end(), c) - disc.begin() - 1;
            cout << tsum(ka, kb) << endl;
        }
        /*
        for(int j = 0; j < disc.size(); j++) {
            cout << tree[n + j] << (j == disc.size()-1 ? '\n' : ' ');
        }
        */
    }

    return 0;
}
