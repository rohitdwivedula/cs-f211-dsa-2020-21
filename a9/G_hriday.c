/**
 * Hriday G
 * 2019A7PS1212H
 * 10.04.2021 12:29:29
 * Time complexity: O(n)
**/
#include <stdio.h>
#define max(x, y) x > (y)? x : (y)

int main() {
    int i, n, s, ans = 0;
    scanf("%d %d", &n, &s);
    while(n--) {
        int x; char c; scanf("%d %c", &x, &c);
        ans = max(ans, c == 'L'? x : s-x);
    } printf("%d", ans);
}