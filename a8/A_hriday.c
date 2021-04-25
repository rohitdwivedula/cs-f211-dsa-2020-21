/**
 * Hriday G
 * 2019A7PS1212H
 * 30.03.2021 19:56:13
 * Time complexity: O(n)
**/
#include <stdio.h>
#include <stdlib.h>
#define N 100005

typedef struct node {
    int val;
    struct node *c[2];
} node;

int main() {
    int i, j, n, cnt[2] = {};
    scanf("%d", &n);

    node *tree = calloc(n, sizeof *tree);
    for(i = 0; i < n; i++)
        scanf("%d", &tree[i].val);

    for(i = 1; i < n; i++) {
        int p, c; char d;
        scanf("%d %d %c", &p, &c, &d);
        tree[p].c[d == 'R'] = &tree[c];
    }

    static node *st[2][N];
    st[0][cnt[0]++] = &tree[0];

    for(i = 0; j = i, cnt[i]; i ^= !cnt[i]) {
        node *v = st[i][--cnt[i]];
        printf("%d ", v->val);
        do if(v->c[j]) st[i^1][cnt[i^1]++] = v->c[j];
        while(j ^= 1, j ^ i);
    }
}