#include<cstdio>
using namespace std;
long long n;
int main() {
    scanf("%lld", &n);
    while(n != 1) {
        printf("%lld ", n);
        if(n & 1) n += (n << 1) + 1;
        else n = n >> 1;
    }
    printf("%lld\n", n);
    return 0;
}
