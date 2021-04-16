/**
 * Hriday G
 * 2019A7PS1212H
 * 08.04.2021 21:52:38
 * Precompute the set of prefix values
 * and use each value's index in the sorted
 * array as its perfect hash (can be found in
 * O(logn) using binary search)
 * Time complexity: O(nlogn)
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10005
#define INF 1000000000
#define chmin(x, y) (y < x? x = y, 1 : 0)
typedef long long ll;

ll p[N], occ[N];
int n, a[N];
 
int less(const void *x, const void *y) {
   return *(ll *)x - *(ll *)y;
}
 
int find(ll val) {
    int lo = 0, hi = n;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(p[mid] < val) lo = mid + 1;
        else hi = mid - 1;
    } return lo;
}
 
int main() {
    int i, ans = INF, l, r; ll sum = 0;
    scanf("%d ", &n);
    for(i = 1; i <= n; i++) {
        char c; scanf("%c", &c);
        a[i] = c == 'L'? +1 : c == 'R'? -1 : c == 'U'? +INF : -INF;
        p[i] = p[i-1] + a[i];
    }
 
    memset(occ, -1, (n+1) * sizeof *occ);
    qsort(p, n+1, sizeof *p, less);
    occ[find(0)] = 0;
 
    for(i = 1; i <= n; i++) {
        sum += a[i];
        int pos = find(sum);
        if(~occ[pos] && chmin(ans, i-occ[pos]))
            l = occ[pos], r = i;
        occ[pos] = i;
    }
 
    if(ans == INF) printf("-1");
    else printf("%d %d", l+1, r);
}