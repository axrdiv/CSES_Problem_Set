#include<cstdio>
#include<algorithm>
using namespace std;
char c, tmp;
int rep, maxrep;

int main() {
    while(scanf("%c", &c) != -1) {
        if(c != tmp) rep = 1;
        else rep++;
        maxrep = max(rep, maxrep);
        tmp = c;
    }

    printf("%d\n", maxrep);

    return 0;
}
