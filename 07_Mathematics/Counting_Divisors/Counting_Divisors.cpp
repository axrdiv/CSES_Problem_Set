#include<cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int count[maxn * 10];
int n;
int x;

void init() {
    for(int i = 1; i <= 1e6; i++)
        for(int j = i; j <= 1e6; j += i)
            count[j]++;

}

int main() {
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d\n", count[x]);
    }

    return 0;
}
