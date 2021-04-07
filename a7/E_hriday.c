/**
 * Hriday G
 * 2019A7PS1212H
 * 08.04.2021 02:43:58
 * Bitmasks
 * Time complexity: O(n * log10 x) per test case
**/
#include <stdio.h>
#include <string.h>
#define M 11
int cnt[1 << M];

int main() {
    int i, n, x; char s[10];
    for(scanf("%d", &n); n--; ) {
        scanf(" %s %d", s, &x);
        int mask = 0;
        for(i = 0; i < M; i++, x /= 10)
            mask += (x % 10 & 1) << i;
        if(!strcmp(s, "add")) cnt[mask]++;
        else if(!strcmp(s, "delete")) cnt[mask]--;
        else printf("%d\n", cnt[mask]);
    }
}