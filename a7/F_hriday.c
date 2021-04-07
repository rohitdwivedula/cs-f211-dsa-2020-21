/**
 * Hriday G
 * 2019A7PS1212H
 * 08.04.2021 02:06:11
 * Trie (to check duplicates in O(|s|))
 * Time complexity: O(Σ |s|)
**/
#include <stdio.h>
#include <string.h>
#define N 500005
#define A 26
int t[N][A];
char s[N];

int main() {
    int Q;
    for(scanf("%d", &Q); Q--; ) {
        int n, sz = 1, win = 0, itsover = 0; char prvc;
        scanf("%d", &n);
        for(int i = 0, j, p; p = 0, i < n; i++, prvc = s[j-1]) {
            scanf(" %s", s);
            if(i && s[0] ^ prvc)
                itsover = 1;
            if(itsover) continue;
            int prvsz = sz;
            for(j = 0; s[j]; j++)
                p = t[p][s[j]-'a'] = t[p][s[j]-'a']? t[p][s[j]-'a'] : sz++;
            if(prvsz == sz)
                itsover = 1;
            else win ^= 1;
        } memset(t, 0, sz * A * sizeof **t);
        printf("%s ", win? "Alice" : "Bob");
    }
}