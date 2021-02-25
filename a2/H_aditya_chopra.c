#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t fast_log2(uint32_t n) {
    uint16_t k = 0;
    while (n >>= 1) k++;
    return k;
}

int main() {
    uint32_t n, level = 0;
    scanf("%d%*c", &n);

    int bt[n];

    for (size_t i = 0; i < n; i++) scanf("%d%*c", bt + i);

    uint64_t aggregate = 0;

    uint16_t log2n = fast_log2(n + 1), rear = 0;

    for (size_t lvl = 0; lvl < log2n; ++lvl) {
        uint64_t numElem = (1 << lvl);

        for (size_t i = 0; i < numElem; ++i) {
            aggregate += bt[rear++] * (lvl + 1);
        }
    }

    printf("%ld", aggregate);

    return 0;
}