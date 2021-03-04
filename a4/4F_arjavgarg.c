#include <stdio.h>
#include <stdlib.h>

typedef struct amp {
	
	int x;
	int y;
	int pow;
	
}  amp_t;

int cmpfunc (const void * a, const void * b) {
	amp_t a1 = *(amp_t*)a, a2 = *(amp_t*)b;
	return (a1.y - a1.x) > (a2.y-a2.x);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t --> 0) {
		int n;
		scanf("%d", &n);
		amp_t amps[n];
		int i;
		long long int sum2 = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &(amps[i].x), &(amps[i].y), &(amps[i].pow));
			sum2 += amps[i].pow;
		}

		qsort(amps, n, sizeof(amps[0]), cmpfunc);
		long long int sum1 = 0;
		int flag = 0;
		for(i = 0; i < n; i++) {
			if(sum1 == sum2) {
				flag = 1;
				break;
			}
			sum1 += amps[i].pow;
			sum2 -= amps[i].pow;
		}
		printf("%s\n", flag?"YES":"NO");
	}

	return 0;
}