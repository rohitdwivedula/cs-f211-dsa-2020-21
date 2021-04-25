/**
 * Hriday G
 * 2019A7PS1212H
 * 05.04.2021 11:13:36
 * Offline perfect hashing via binary search
 * Time complexity: O(nlogn)
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200005
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
    int i, ans = 0; ll sum = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", a+i);
        p[i] = p[i-1] + a[i];
    }
 
    memset(occ, -1, (n+1) * sizeof *occ);
    qsort(p, n+1, sizeof *p, less);
    occ[find(0)] = 0;
 
    for(i = 1; i <= n; i++) {
        sum += a[i];
        int pos = find(sum);
        if(~occ[pos])
            ans = ans < i-occ[pos]? i-occ[pos] : ans;
        else occ[pos] = i;
    }
 
    printf("%d", ans);
}