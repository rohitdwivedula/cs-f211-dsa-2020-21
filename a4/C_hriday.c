/**
 * Hriday G
 * 2019A7PS1212H
 * 21.02.2021 15:20:38
 * Time complexity: O(n*len*A*logn) using double hashes
     where len denotes max word length and A denotes alphabet size
 * Note1: Can be optimized to O(n*len*A)
     using hash tables for O(1) access (on average)
 * Note2: rand() is bad, not uniform. So anti hash cases CAN be
     generated if one has quite a bit of time and patience. Good luck :).
**/
/*
    The main observation that allows you to optimize from quadratic to
    linear time in n is the fact that there are a finite and relatively
    small number of possible edges from a given word. We brute each
    possible next word in O(len * A) and perform an update if the word exists
    efficiently (O(logn) using binary search, but O(1) avg using hash table
    is also possible). The problem is now just a bfs starting from the first
    word. The least distance among all words that meet the final condition
    is printed.
    Dictionary has ~10^5 words, so this should pass.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 100005
#define LEN 15
typedef unsigned long long u64;
typedef struct {
    int id, h1; u64 h2;
} hash_t;

// double hash: mod1=1e9+123, mod2=2^64, base=random
const int mod = 1000000123;
int base;
hash_t hashes[N];

hash_t gen_hash(const char *s) {
    int suf1 = 0; u64 suf2 = 0;
    for(int i = strlen(s)-1; ~i; i--) {
        suf1 = (1LL * suf1 * base + s[i]) % mod;
        suf2 = suf2 * base + s[i];
    } return (hash_t){-1, suf1, suf2};
}

int less(const void *_A, const void *_B) {
    const hash_t *A = _A, *B = _B;
    if(A->h1 == B->h1) {
        return A->h2 == B->h2? 0 : A->h2 < B->h2? -1 : +1;
    } else {
        return A->h1 < B->h1? -1 : +1;
    }
}

int d[N], m, len;
char s[N][LEN];

// binary search
int binsearch(hash_t x) {
    int lo = 0, hi = m-1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        int o = less(&hashes[mid], &x);
        if(o == 0)
            return hashes[mid].id;
        if(o < 0) lo = mid + 1;
        else hi = mid - 1;
    } return -1;
}

// bfs
void bfs(int root) {
    memset(d, -1, m * sizeof *d);
    int q[N], front = 0, back = 0;
    q[back++] = root; d[root] = 0;
    while(front < back) {
        int v = q[front++];
        char nxt[LEN]; strcpy(nxt, s[v]);
        for(int i = 0; i < len; i++) {
            for(nxt[i] = 'a'; nxt[i] <= 'z'; nxt[i]++) {
                if(nxt[i] != s[v][i]) {
                    hash_t nxt_hash = gen_hash(nxt);
                    int idx = binsearch(nxt_hash);
                    if(~idx && d[idx] == -1) {
                        d[idx] = d[v] + 1;
                        q[back++] = idx;
                    }
                }
            } nxt[i] = s[v][i];
        }
    }
}

int main() {    
    srand(time(NULL));
    base = 256 + (rand() << 15 ^ rand()) % (mod - 258) | 1;

    int n;
    scanf("%d %s", &n, s[m++]);
    hashes[0] = gen_hash(s[0]);
    hashes[0].id = 0;
    len = strlen(s[0]);
    
    for(int i = 0; i < n; i++) {
        scanf(" %s", s[m]);
        if(strlen(s[m]) != len) continue;
        hashes[m] = gen_hash(s[m]);
        hashes[m].id = m; m++;
    }
    qsort(hashes, m, sizeof *hashes, less);

    bfs(0);
    int ans = N+N;
    for(int i = 1; i < m; i++) {
        int bad = 0;
        for(int j = 0; j < len; j++)
            bad |= s[0][j] == s[i][j];
        if(!bad && ~d[i]) ans = d[i] < ans? d[i] : ans;
    }
    
    printf("%d", ans == N+N? -1 : ans-1);
}