/**
 * Hriday G
 * 2019A7PS1212H
 * 26.03.2021 19:51:33
 * DP
 * Time Complexity: O(n + m)
    where n and m denote string lengths
**/
#include <stdio.h>
#include <string.h>
#define min(x, y) (x < y? x : y)
#define N 200005
char s[N], t[N], ans[N];
int nxt[2][N];

int main() {
    int n, m, i, j, k = 0;
    scanf("%s %s", s, t);
    n = strlen(s); m = strlen(t);

    for(i = n-1; ~i; i--)
        nxt[0][i] = s[i] == s[i+1]? nxt[0][i+1] + 1 : 1;
    for(j = m-1; ~j; j--)
        nxt[1][j] = t[j] == t[j+1]? nxt[1][j+1] + 1 : 1;
    
    for(i = j = 0; i < n && j < m; ) {
        int mn = min(nxt[0][i], nxt[1][j]);
        ans[k++] = (s[i] == t[j]? s[i + mn] > t[j + mn] : s[i] > t[j])? s[i++] : t[j++];
    }

    while(i < n) ans[k++] = s[i++];
    while(j < m) ans[k++] = t[j++];
    ans[k] = '\0';
    
    printf("%s", ans);
}

/*
Some cases to look out for (swap the two strings as well):
221
223

22
221

22
223

223
2224
*/