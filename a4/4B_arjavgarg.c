#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int positions[n];
	int strengths[n];
	int i;
	for(i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		positions[i] = i+1;
		strengths[i] = x;
	}
	
	int leftover = n;
	while(leftover > 1) {
		int j = -1;
		for(i = 0; i < n; i++) {
			int r1 = strengths[i];
			int p1 = positions[i];
			i++;
			if(i == n) {
				strengths[i-1] += b;
				strengths[leftover-1] = strengths[i-1];
				positions[leftover-1] = positions[i-1];
				positions[i-1] = strengths[i-1] = -1;
			}
			else {
				int r2 = strengths[i];
				int p2 = positions[i];
				if(r1 > r2) {
					positions[i-1] = strengths[i-1] = positions[i] = strengths[i] = -1;
					strengths[++j] = abs(r1 - a*(r1-r2));
					positions[j] = p1;
					leftover--;
				}
				else if(r1 == r2) {
					leftover -= 2;
					positions[i-1] = strengths[i-1] = positions[i] = strengths[i] = -1;
				}
				else {
					positions[i-1] = strengths[i-1] = positions[i] = strengths[i] = -1;
					strengths[++j] = abs(r2 - a*(r2-r1));
					positions[j] = p2;
					leftover--;
				}
			}
		}
		n = leftover;
	}
	
	if(leftover) {
		printf("%d %d", positions[0], strengths[0]);
	}
	else {
		printf("-1 -1");
	}

	return 0;
}