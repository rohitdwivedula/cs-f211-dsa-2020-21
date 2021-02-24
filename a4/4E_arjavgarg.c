#include <stdio.h>

int get_quad(int x, int y) {
	if(x < 0) {
		if(y < 0) {
			return 3;
		}
		return 2;
	}
	if(y < 0) {
		return 4;
	}
	return 1;
}

int partiton(int l, int h, int n, int x[n], int y[n]) {
	int i = l, j;
	for(j = l+1; j <= h; j++) {
		int quadj = get_quad(x[j], y[j]);
		int quadl = get_quad(x[l], y[j]);
		
		if(quadj < quadl || (quadj==quadl && (quadj&1? (y[j]/(double)x[j]<y[l]/(double)x[l]) : (y[j]/(double)x[j]>y[l]/(double)x[l])))) {
			i++;
			int tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			
			tmp = y[i];
			y[i] = y[j];
			y[j] = tmp;
		}
	}
	
	int tmp = x[i];
	x[i] = x[l];
	x[l] = tmp;
	
	tmp = y[i];
	y[i] = y[l];
	y[l] = tmp;
	
	return i;
}

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

void quicksort(int l, int h, int n, int x[n], int y[n]) {
	if(l < h) {
		int part = partiton(l, h, n, x, y);
		quicksort(l, part-1, n, x, y);
		quicksort(part+1, h, n, x, y);
	}
}

int main() {
	int m;
	int x[m];
	int y[m];
	int i;
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &(x[i]), &(y[i]));
	}

	quicksort(0, m-1, m, x, y);
	
	long long int sum = 0;
	for(i = 1; i < m; i++) {
		sum += abs(y[i]-y[i-1]) + abs(x[i]-x[i-1]);
	}
	
	sum += abs(y[0]-y[m-1]) + abs(x[0]-x[m-1]);
	
	printf("%d\n", sum);

	return 0;
}