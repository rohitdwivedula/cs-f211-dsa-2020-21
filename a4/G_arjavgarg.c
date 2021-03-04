#include <stdio.h>

long long int swapsort(int n, int arr[n], int l, int h) {
	long long int total = 0;
	if(l < h) {
		int sorted_arr[h-l+1];
		int c1 = 0, c2 = 0;
		int M = (l+h)/2;
		total += swapsort(n, arr, l, M);
		total += swapsort(n, arr, M+1, h);
		int len1 = M-l+1;
		int len2 = h-M;
		int i;
		for(i = 0; i < h-l+1; i++) {
			if(c1 < len1) {
				if(c2 < len2) {
					int a = arr[c1+l];
					int b = arr[c2+M+1];
					if(b < a) {
						total += len1-c1;
						sorted_arr[i] = b;
						c2++;
					}
					else {
						sorted_arr[i] = a;
						c1++;
					}
				}
				else {
					sorted_arr[i] = arr[c1+l];
					c1++;
				}
			}
			else {
				sorted_arr[i] = arr[c2+M+1];
				c2++;
			}
		}
		for(i = l; i <= h; i++) {
			arr[i] = sorted_arr[i-l];
		}
	}
	return total;
}
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &(a[i]));
	}

	printf("%lld", swapsort(n, a, 0, n-1));

	return 0;
}