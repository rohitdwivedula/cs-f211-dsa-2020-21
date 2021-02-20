#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t nC2(uint32_t n) {
    return n * (n - 1) * 0.5;
}

int main() {
    uint32_t n, c;
    scanf("%d%*c%d%*c", &n, &c);

    char tags[n][21];

    for (int i = 0; i < n; i++) scanf("%s%*c", *(tags + i));

    uint32_t fam[43] = {0}, numFights = 0;

    for (int i = 0; i < n; i++) 
        fam[ tags[i][0] - '0']++;
    
    for (int i = 0; i < 43; i++) {
        if (fam[i] > c) {
            uint32_t q = fam[i] / c, r = fam[i] % c;

            // q num of animals per cage
            numFights += nC2(q) * (c - r);

            // q + 1 animals per cage
            numFights += nC2(q + 1) * r;
        }
    }
    
    printf("%d", numFights);

    return 0;
}