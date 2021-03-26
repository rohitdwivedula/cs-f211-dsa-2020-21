/**
 * Hriday G
 * 2019A7PS1212H
 * 14.03.2021 11:09:08
 * Binary search over answer
 * Time Complexity: O((n + k)log(max ai)) to insert average
    O(n log(max ai)) to insert any integer
 * Note: straightforward O(klogn) greedy solution using
         priority queue exists for the average task
**/
#include <stdio.h>
#define N 100005
#define INF 1000000000  // e9
int a[N], n, k, left;

/* Insert average */
int f(int diff, int mx) {
    if(diff <= mx) return 1;
    if(--left < 0) return 0;
    return f(diff >> 1, mx) && f(diff+1 >> 1, mx);
}

/*  Insert any integer
int g(int diff, int mx) {
    return (left -= (diff+mx-1)/mx - 1) >= 0;
} */

int check(int x) {
    left = k;
    for(int i = 1; i < n; i++)
        if(!f(a[i] - a[i-1], x)) return 0;
    return 1;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    int lo = 0, hi = INF;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    printf("%d", lo);
}