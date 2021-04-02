#include <stdio.h>

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void Max_Heapify(int a[], int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && a[largest] < a[l]) 
		largest = l;

	if(r < n && a[largest] < a[r])
		largest = r;

	if(largest != i) {
		swap(&a[i],&a[largest]);
		Max_Heapify(a, n, largest);
	}

	return;
	
}

void Build_Max_Heap(int a[], int n) {

	int start = n/2 - 1;

	for(int i = start; i >= 0; i--) {
		Max_Heapify(a, n, i);
	}

	return;                                                                                       
}
int Eat(int a[], int n) {
	int chocolates = a[0];
	a[0] = a[0]/3;
	Max_Heapify(a,n,0);
	return chocolates;
}
int main() {
	int n, d;
	scanf("%d %d",&n, &d);

	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	Build_Max_Heap(a,n);
	int ans = 0;
	for(int i = 0; i < d; i++) {
		ans += Eat(a,n);
		ans %= 1000000007;
	}

	printf("%d",ans);

	return 0;
}