/**
 * Hriday G
 * 2019A7PS1212H
 * 24.01.2021 02:55:10
 * Bipartite graph checking using
    Disjoint set union with union by rank (logn merges)
 * Time complexity: O(min(n, m) * logn + m)
    since there can be atmost n-1 merges
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(x, y) _ = x, x = y, y = _
#define N 505
int _, par[N], val[N];

int get_par(int *u) {
    int v = 0;
    while(par[*u] >= 0) {
        v ^= val[*u];
        *u = par[*u];
    } return v;
}

int merge(int u, int v) {
    int x = get_par(&u), y = get_par(&v);
    if(u == v) {
        return x ^ y;
    } else {
        if(-par[u] < -par[v]) {
            swap(u, v); swap(x, y);
        } par[u] += par[v]; par[v] = u;
        val[v] = x^y^1;
    } return 1;
}

int main() {
    int i, j, n, m;
    scanf("%d %d", &n, &m);
    
    memset(par, -1, (n+1) * sizeof *par);
    while(m--) {
        int u, v; scanf("%d %d", &u, &v);
        if(!merge(u, v))
            printf("NEED MORE COLOURS"), exit(0);
    }

    int x = get_par(&m);
    for(i = j = 0; i < n; j = ++i)
        printf("%c", get_par(&j) ^ x? 'B' : 'R');
}
