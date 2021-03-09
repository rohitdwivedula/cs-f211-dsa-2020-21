/**
 * Hriday G
 * 2019A7PS1212H
 * 14.02.2021 21:57:15
 * Time complexity: O(nlogn)
**/
#include <stdio.h>
#include <stdlib.h>
#define N 100005

typedef struct {
    int y, p;
} T;
T points[N];

int cmp(const void *A, const void *B) { 
    return ((T*)A)->y - ((T*)B)->y;
}

int main() {
    int Q;
    for(scanf("%d", &Q); Q--; ) {
        int i, j, n; scanf("%d", &n);
        long long left = 0, right = 0;
        for(i = 0; i < n; i++) {
            int x, y, w; scanf("%d %d %d", &x, &y, &w);
            points[i].y = y - x;
            points[i].p = w; right += w;
        } qsort(points, n, sizeof *points, cmp);

        for(i = j = 0; i < n; i = j) {
            if(left == right) {
                printf("YES\n");
                goto next;
            }
            while(j < n && points[j].y == points[i].y)
                left += points[j].p, right -= points[j].p, j++;
        }

        printf("NO\n");
        next: ;
    }
}
