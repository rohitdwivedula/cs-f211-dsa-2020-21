/**
 * Hriday G
 * 2019A7PS1212H
 * 08.04.2021 21:48:04
 * Time complexity: O(n)
**/
#include <stdio.h>
#define N 100005
int f[N];

int main() {
    int i, n, ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if(x > n) ans++;
        else f[x]++;
    }

    for(i = 1; i < N; i++)
        ans += f[i] < i? f[i] : f[i] - i;

    printf("%d", ans);
}