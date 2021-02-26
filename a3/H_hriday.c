/**
 * Hriday G
 * 2019A7PS1212H
 * 14.02.2021 19:36:36
 * Time complexity: O(nlogn)
**/
#include <stdio.h>
#include <stdlib.h>
#define N 100005
int who[N], indeg[N], order[N], ans[N];

int cmp(const void *A, const void *B) { return indeg[*(int*)B] - indeg[*(int*)A]; }

int main() {
    int i, k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", who+i);
    for(i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        indeg[v]++;
    }

    for(i = 0; i < n; i++) order[i] = i;
    qsort(order, n, sizeof *order, cmp);
    
    for(i = 0; i < n; i++)
        ans[who[order[i]]] = indeg[order[i]];

    for(i = 0; i < k; i++)
        printf("%d%c", ans[i], " \n"[i+1 == k]);
}
