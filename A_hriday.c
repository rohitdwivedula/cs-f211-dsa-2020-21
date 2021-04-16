/**
 * Hriday G
 * 2019A7PS1212H
 * 10.04.2021 11:44:25
 * Red Black tree
 * Time complexity: O((Q+n)logn)
 * Note: Implementation has been abstracted away to
 *  a separate C file, included via a header, for cleaner code
 *   https://github.com/the-hyp0cr1t3/RB_tree
**/
#include <stdio.h>
#include "RBtree.h"

int main() {
    int i, n, Q;
    scanf("%d", &n);
    Rb_tree map = newrbtree();
    for(i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        insert(&map, x).it->val++;
    }

    scanf("%d", &Q);
    while(Q--) {
        int x; scanf("%d", &x);
        printf("%d\n", insert(&map, x).it->val);
    }
}
// gcc <filename> RBtree.c -o a