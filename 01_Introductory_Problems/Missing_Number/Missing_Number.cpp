#include<cstdio>
using namespace std;
const int maxn = 200000 + 5;
bool exist[maxn];
int n, tmp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        exist[tmp] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(exist[i]) continue;
        printf("%d\n", i);
        break;
    }

    return 0;
}
