/**
 * Hriday G
 * 2019A7PS1212H
 * 14.02.2021 21:16:27
 * Time complexity: O(nlogn)
**/
#include <stdio.h>
#define abs(x) x < 0? -(x) : x
#define swap(x, y, _) _ = x, x = y, y = _
#define N 100005
int ___[4][N];

int main() {
    int *id =     ___[0];
    int *r =      ___[1];
    int *new_id = ___[2];
    int *new_r =  ___[3];
    int *_; int __;

    int i, n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(i = 0; i < n; i++) {
        scanf("%d", r+i);
        id[i] = i;
    }

    while(n > 1) {
        int m = 0;
        for(i = 0; i+1 < n; i += 2) {
            if(r[i] == r[i+1]) continue;
            if(r[i+1] > r[i]) {
                swap(r[i], r[i+1], __);
                swap(id[i], id[i+1], __);
            }
            new_id[m] = id[i];
            new_r[m++] = abs(r[i] - a * (r[i] - r[i+1]));
        }
        if(i < n) {
            new_id[m] = id[i];
            new_r[m++] = r[i] + b;
        }
        n = m;
        swap(r, new_r, _);
        swap(id, new_id, _);
    }

    if(n) printf("%d %d", *id + 1, *r);
    else printf("-1 -1");
}