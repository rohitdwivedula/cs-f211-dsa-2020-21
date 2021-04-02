/**
 * Hriday G
 * 2019A7PS1212H
 * 24.01.2021 01:12:56
 * Reorder elements once and precompute
    partial sums (prefix sums) for O(1) range queries
 * Time complexity: O(n)
**/
#include <stdio.h>
#define chmax(x, y) (x = x < y? y : x)
#define chmin(x, y) (x = x > y? y : x)
typedef long long ll;
#define N 505
#define INF 1000000000000000LL
int a[N];
ll pref2[N << 1], pref3[N << 1];

ll get(ll *p, int l, int r) {
    return p[r] - p[l];
}

int main() {
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(~n&1) {
            pref2[i&1] += a[i] * a[i];
            pref3[i&1] += a[i] * a[i] * a[i];
        }
    }

    if(~n&1) {
        ll val = pref2[0]-pref3[1] - pref2[1]+pref3[0];
        printf("%lld", val < 0? -val : val);
        return 0;
    }

    for(j = 1, i = 0; j == 1 || i; i = (i+2)%n, j++) {
        pref2[j] = pref2[j+n] = a[i] * a[i];
        pref3[j] = pref3[j+n] = a[i] * a[i] * a[i];
    }

    for(i = 1; i <= 2*n; i++) {
        pref2[i] += pref2[i-1];
        pref3[i] += pref3[i-1];
    }

    ll mx = -INF, mn = INF;
    for(i = n+1>>1; i+n/2 <= 2*n; i++) {
        chmax(mx, get(pref2, i-(n+1>>1), i) - get(pref3, i, i+n/2));
        chmin(mn, get(pref2, i-(n+1>>1), i) - get(pref3, i, i+n/2));
    }

    printf("%lld", mx-mn);
    return 0;
}
