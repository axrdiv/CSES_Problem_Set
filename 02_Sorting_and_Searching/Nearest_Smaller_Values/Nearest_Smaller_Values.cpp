#include<cstdio>
using namespace std;
const int maxn = 2 * 1e5 + 5;

int n, top;
int vec[maxn], st[maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &vec[i]);
        while(top && vec[st[top - 1]] >= vec[i])
            top--;
        printf("%d%c", (top ? st[top-1] : 0), (i == n ? '\n' : ' '));
        st[top++] = i;
    }

    return 0;
}
