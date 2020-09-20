#include<cstdio>
using namespace std;
char resv[10][10];
bool hor[20], dia1[20], dia2[20];
int ans;

void dfs(int dep, const int &n) {
    if(dep == n) {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(resv[dep][i] == '*') continue;
        if(hor[i] || dia1[n + dep - i] || dia2[dep + i]) continue;
        hor[i] = dia1[n + dep - i] = dia2[dep + i] = 1;
        dfs(dep + 1, n);
        hor[i] = dia1[n + dep - i] = dia2[dep + i] = 0;
    }
}

int main() {
    for(int i = 0; i < 8; i++)
        scanf("%s", resv[i]);
    dfs(0, 8);
    printf("%d\n", ans);
    return 0;
}
