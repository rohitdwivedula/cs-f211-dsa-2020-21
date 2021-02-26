#include <stdio.h>

int merge(int a[], int b[], int left, int mid, int right) 
{ 
	int cnt = 0; 

	int i = left; 
	int j = mid; 
	int k = left; 
	while ((i <= mid - 1) && (j <= right)) { 
		if (a[i] <= a[j]) 
			b[k++] = a[i++]; 
		else 
			b[k++] = a[j++], cnt = cnt + (mid - i); 
	} 

	while (i <= mid - 1) 
		b[k++] = a[i++]; 

	while (j <= right) 
		b[k++] = a[j++]; 

	for (i=left; i <= right; i++) 
		a[i] = b[i]; 

	return cnt; 
} 

int mergeSort(int a[], int b[], int left, int right) 
{ 
	int mid, cnt = 0; 
	if (right > left) { 

		mid = (right + left)/2; 
		cnt = mergeSort(a, b, left, mid); 
		cnt += mergeSort(a, b, mid+1, right); 
		cnt += merge(a, b, left, mid+1, right); 
	} 

	return cnt; 
} 

int main() { 
	int n;
	scanf("%d",&n);
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	int swaps = mergeSort(a, b, 0, n - 1);
	printf("%d",swaps);
	
	return 0; 
} 
