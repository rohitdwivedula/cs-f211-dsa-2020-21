#include <stdio.h>

int partiton(int l, int h, int n, double arr[n], int pos[n]) {
	int i = l, j;
	for(j = l+1; j <= h; j++) {
		if(arr[j] > arr[l] || (arr[j] == arr[l] && pos[j] < pos[l])) {
			i++;
			double tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			
			int tmp2 = pos[i];
			pos[i] = pos[j];
			pos[j] = tmp2;
		}
	}
	
	double tmp = arr[i];
	arr[i] = arr[l];
	arr[l] = tmp;
	int tmp2 = pos[i];
	pos[i] = pos[l];
	pos[l] = tmp2;
	
	return i;
}

void quicksort(int l, int h, int n, double arr[n], int pos[n]) {
	if(l < h) {
		int part = partiton(l, h, n, arr, pos);
		quicksort(l, part-1, n, arr, pos);
		quicksort(part+1, h, n, arr, pos);
	}
}

void proc_outcome(int n, double is_lastp[n], double p[n][n], double no_clickp[n], double reach_prob, int current) {
	int i;
	is_lastp[current] += no_clickp[current]*reach_prob;
	for(i = 0; i < n; i++) {
		if(p[current][i]) {
			proc_outcome(n, is_lastp, p, no_clickp, reach_prob*p[current][i], i);
		}
	}
}

int main() {
	int n, e, s;
	scanf("%d %d %d", &n, &e, &s);
	double p[n][n];
	int i, j;
	double is_lastp[n]; // ith article will be the last
	double no_clickp[n]; // no link on ith article would be clicked
	int positions[n]; 
	for(i = 0; i < n; i++) {
		is_lastp[i] = 0;
		positions[i] = i;
		no_clickp[i] = 1;
		for(j = 0; j < n; j++) {
			p[i][j] = 0;
		}
	}
	
	for(i = 0; i < e; i++) {
		int wi, wj;
		double pij;
		scanf("%d %d %lf", &wi, &wj, &pij);
		p[wi][wj] = pij;
		no_clickp[wi] -= pij;
	}
	
	proc_outcome(n, is_lastp, p, no_clickp, 1, s);
	
	quicksort(0, n-1, n, is_lastp, positions);
	
	for(i = 0; i < n; i++) printf("%d ", positions[i], is_lastp[i]);

	return 0;
}