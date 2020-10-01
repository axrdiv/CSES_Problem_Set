/*
 * LIS Problems O(nlogn)
 */
#include<cstdio>
#include<vector>
using namespace std;
int n, top;
vector<int> dp;


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        auto it = lower_bound(dp.begin(), dp.end(), tmp);
        if(it == dp.end()) {
            dp.push_back(tmp);
        }
        else {
            *it = tmp;
        }
    }

    printf("%d\n", (int)dp.size());


    return 0;
}
