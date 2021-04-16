/**
 * Hriday G
 * 2019A7PS1212H
 * 13.04.2021 23:49:00
 * Time complexity: O(nlog(ai) + nlogn)
**/
#include <stdio.h>
#include <stdlib.h>
#define N 100005
#define LG 18
int a[N * LG];

int cmp(const void *x, const void *y) {
    return *(int *)x - *(int *)y;
}

int main() {
    int i, j, n, k = 0, ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        while(~x & 1) a[k++] = x, x >>= 1;
    }

    qsort(a, k, sizeof *a, cmp);
    for(i = j = 0; i < k; i = j, ans++)
        while(j < k && a[j] == a[i]) j++;
        
    printf("%d", ans);
}