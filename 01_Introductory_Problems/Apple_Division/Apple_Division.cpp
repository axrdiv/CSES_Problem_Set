#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 20 + 5;
long long n, apples[maxn];
long long sum;
long long opti = 1e10;



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> apples[i];
        sum += (long long)apples[i];
    }

    for(int i = 0; i < (1<<n); i++) {
        long long weight = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) weight += apples[j];
        }
        opti = min(opti, abs(sum - 2 * weight));
    }

    cout << opti << endl;
    return 0;
}
