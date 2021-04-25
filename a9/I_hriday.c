/**
 * Hriday G
 * 2019A7PS1212H
 * 10.04.2021 12:40:08
 * Time complexity: O(n + A*A) where A = 360°
**/
#include <stdio.h>
#include <string.h>
#define k_II 1000000000000000000LL //e18
#define A 360
#define chmax(x, y) (y > x? x = y, 1 : 0)
#define chmin(x, y) (y < x? x = y, 1 : 0)
long long f[2*A], p[3*A];

int main() {
    int i, j, n, k; long long ans = k_II;
    scanf("%d %d", &n, &k); ++k;

    while(n--) {
        int x, h; scanf("%d", &x);
        x %= A; h = 1;              // input health value h for additional subtask
        chmax(f[x], h);
    }

    for(i = 0; i < A; i++)
        f[i+A] = f[i];

    for(i = 0; i < A; i++) {
        long long res = 0;
        for(j = i; j < i+A; j++) {
            long long diff = p[j] < f[j]? f[j] - p[j] : 0LL;
            res += diff;
            p[j] += diff;
            p[j+k] -= diff;
            p[j+1] += p[j];
        } memset(p, 0, sizeof(p));
        chmin(ans, res);
    }

    printf("%lld", ans);
}