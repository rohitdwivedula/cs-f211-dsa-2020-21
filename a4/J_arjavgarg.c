#include <stdio.h>

int bin_search(int l, int h, int n, int arr[n], char is_inc, int x) {
	if(l <= h) {
		int M = (l+h)/2;
		if(arr[M] == x) return M;
		if((arr[M] > x && is_inc) || (arr[M] < x && !is_inc)) return bin_search(l, M-1, n, arr, is_inc, x);
		return bin_search(M+1, h, n, arr, is_inc, x);
	}
	
	return -1;
}

int main() {
	int n, q;
	scanf("%d %d", &n , &q);
	int notes[n];
	int i;
	int max;
	scanf("%d", &max);
	int pos = 0;
	notes[0] = max;
	for(i = 0; i < n-1; i++) {
		scanf("%d", &(notes[i+1]));
		if(max < notes[i+1]) {
			max = notes[i+1]; 
			pos = i+1;
		}
	}
	
	while(q-->0) {
		int t;
		scanf("%d", &t);
		if(bin_search(0, pos, n, notes, 1, t) == -1 && bin_search(pos+1, n-1, n, notes, 0, t) == -1) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}