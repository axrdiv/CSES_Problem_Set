#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, vec[maxn];
int ans;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    sort(vec, vec + n);
    for(int i = 0; i < n; i++) {
        ans++;
        while(i+1 < n && vec[i] == vec[i+1]) i++;
    }

    printf("%d\n", ans);

    return 0;
}
