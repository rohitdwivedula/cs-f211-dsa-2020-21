/**
 * Hriday G
 * 2019A7PS1212H
 * 10.04.2021 21:26:39
 * Time complexity: O(n + Qlogn)
 *  O(n + Q) if queries gave node numbers instead
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N 100005
int order[N], n, ans;

typedef struct node {
    int val;
    struct node *p, *l, *r;
} node;
node *tree;

int cmp(const void *x, const void *y) {
    return tree[*(int *)x].val - tree[*(int *)y].val;
}

int find(int u) {
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(tree[order[mid]].val <= u)
            lo = mid + 1;
        else hi = mid - 1;
    } return order[hi];
}

int dfs(node *u) {
    if(u == NULL) return -1;
    int x = dfs(u->l), y = dfs(u->r);
    ans = ans < 2 + x + y? 2 + x + y : ans;
    return x > y? x+1 : y+1;
}

int main() {
    int i, Q;
    scanf("%d %d", &n, &Q);

    tree = calloc(n, sizeof *tree);
    for(i = 0; i < n; i++) {
        scanf("%d", &tree[i].val);
        order[i] = i;
    }

    qsort(order, n, sizeof *order, cmp);

    for(i = 1; i < n; i++) {
        int p, c; char d;
        scanf("%d %d %c", &p, &c, &d);
        if(d == 'L') tree[p].l = &tree[c];
        else tree[p].r = &tree[c];
        tree[c].p = &tree[p];
    }

    while(Q--) {
        int u, v; static char s[10];
        scanf(" %s %d", s, &u);
        u = find(u);
        if(!strcmp(s, "DELETE")) {      // O(1) deletes
            assert(u);                      // should not delete root, otherwise tree diameter op is meaningless
            if(tree[u].p->l == &tree[u])
                tree[u].p->l = NULL;
            else tree[u].p->r = NULL;
        } else {                        // O(1) swaps
            scanf("%d", &v); v = find(v);
            node *pu = tree[u].p, *pv = tree[v].p;
            if(pu->l == &tree[u]) {
                pu->l = &tree[v];
            } else {
                pu->r = &tree[v];
            } tree[v].p = pu;
            if(pv->l == &tree[v]) {
                pv->l = &tree[u];
            } else {
                pv->r = &tree[u];            
            } tree[u].p = pv;
        }
    }

    dfs(&tree[0]);
    printf("%d", ans);
}