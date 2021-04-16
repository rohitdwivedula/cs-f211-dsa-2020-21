/**
 * Hriday G
 * 2019A7PS1212H
 * 10.04.2021 12:16:54
 * Time complexity: O(n)
**/
#include <stdio.h>
#include <stdlib.h>
#define N 100005
int *g[N], deg[N], x, y, sub[N], found[N];

void add(int u, int v) {
    int o = deg[u]++;
    if(o >= 2 && !(o & o-1))
        g[u] = realloc(g[u], o * 2 * sizeof *g[u]);
    g[u][o] = v;
}

void dfs(int v, int p) {
    found[v] = v == y; sub[v] = 1;
    for(int o = deg[v]; o--; ) {
        int x = g[v][o];
        if(x == p) continue;
        dfs(x, v);
        found[v] |= found[x];
        sub[v] += sub[x];
    }
}

int main() {
    int i, n;
    scanf("%d %d %d", &n, &x, &y);
    for(i = 0; i < n; i++)
        g[i] = malloc(2 * sizeof *g[i]);

    for(i = 0; i < n-1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        --u; --v; add(u, v); add(v, u);
    }
    
    --x; --y;
    dfs(x, -1);

    long long ans = n;
    for(int o = deg[x]; o--; )
        if(found[g[x][o]]) ans -= sub[g[x][o]];

    ans *= sub[y];
    ans = 1LL * n * (n-1) - ans;

    printf("%lld", ans);
}