/**
 * Hriday G
 * 2019A7PS1212H
 * 16.04.2021 13:57:59
 * Time complexity: O(n)
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200005
#define M 11
char a[N][M];
int i, n, pos[N], ans[N];

void dfs(int x) {
    if(ans[x]) {
        dfs(x<<1);
        printf("%s ", a[ans[x]]);
        dfs(x<<1|1);
    }
}

int main() {
    for(scanf("%d", &n), pos[i = 1] = 1; i <= n; i++) {
        scanf(" %s", a[i]);
        if(strcmp(a[i], "-1")) {
            for(int j = 0, k = strlen(a[i])-1; j < k; j++, k--)
                a[i][j] ^= a[i][k] ^= a[i][j] ^= a[i][k];
            pos[i<<1] = pos[i]<<1|1;
            pos[i<<1|1] = pos[i]<<1;
            ans[pos[i]] = i;
        }
    }

    dfs(1);
}