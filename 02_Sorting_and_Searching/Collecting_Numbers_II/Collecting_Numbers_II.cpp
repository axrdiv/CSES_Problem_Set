#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 2*1e5+5;
int n, m, tmp;
vector<int> vec;
int nxt[maxn];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
        nxt[tmp-1] = i;
    }

    set<int> targ; targ.insert(-vec[0]);
    for(int i = 1; i < n; i++) {
        if(*targ.lower_bound(-vec[i]) == -vec[i] + 1)
            targ.erase(targ.lower_bound(-vec[i]));
        targ.insert(-vec[i]);
    }
    int init = targ.size();

    // for(int i = 0; i < n; i++)
    //     cout << vec[i] << (i == n-1 ? "\n" : " ");
    // for(int i = 1; i <= n; i++)
    //     cout << nxt[i] << (i == n ? "\n" : " ");
    // cout << endl;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a != b) {
            if(a > b) swap(a, b);
            int va = vec[a-1], vb = vec[b-1];

            if(va != n && nxt[va] < b && nxt[va] > a)
                init++;
            if(vb != n && nxt[vb] > a && nxt[vb] < b)
                init--;
            if(va != 1 && nxt[va-2] < b && nxt[va-2] > a)
                init--;
            if(vb != 1 && nxt[vb-2] > a && nxt[vb-2] < b)
                init++;

            if(va == vb + 1)
                init--;
            if(vb == va + 1)
                init++;

            nxt[va-1] = b;
            nxt[vb-1] = a;
            swap(vec[a-1], vec[b-1]);
        }

        cout << init << endl;
    }


    return 0;
}
