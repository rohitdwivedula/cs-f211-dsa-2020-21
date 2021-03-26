#include <stdio.h>

typedef struct {
	int l;
	int r;
	int diff;
} HeapNode;

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

void MaxHeapify(HeapNode heapNode[], int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && heapNode[largest].diff < heapNode[l].diff)
		largest = l;
	if(r < n && heapNode[largest].diff < heapNode[r].diff)
		largest = r;
	if(largest != i) {
		swap(&heapNode[i].diff, &heapNode[largest].diff);
		swap(&heapNode[i].l, &heapNode[largest].l);
		swap(&heapNode[i].r, &heapNode[largest].r);
		MaxHeapify(heapNode, n, largest);
	}
}
void Build_Max_Heap(HeapNode heapNode[], int n) {

	int start = n/2 - 1;

	for(int i = start; i >= 0; i--) {
		MaxHeapify(heapNode, n, i);
	}
}

void Insert_Heapify(HeapNode heapNode[], int n, int i) {
	int parent = (i-1)/2;
	if(heapNode[parent].diff < heapNode[i].diff) {
		swap(&heapNode[i].diff, &heapNode[parent].diff);
		swap(&heapNode[i].l, &heapNode[parent].l);
		swap(&heapNode[i].r, &heapNode[parent].r);
		Insert_Heapify(heapNode, n, parent);
	}
}

void insertAverage(HeapNode heapNode[], int n) {
	int avg = (heapNode[0].l + heapNode[0].r) / 2;
	int left = heapNode[0].l, right = heapNode[0].r;
	heapNode[0].l = left;
	heapNode[0].r = avg;
	heapNode[0].diff = heapNode[0].r - heapNode[0].l; 
        MaxHeapify(heapNode,n,0);

	heapNode[n].l = avg;
	heapNode[n].r = right;
	heapNode[n].diff = heapNode[n].r - heapNode[n].l;
	Insert_Heapify(heapNode, n+1, n);

	return;
}

int main() {
	int n, k;
	scanf("%d %d",&n,&k);
	int a[n];

	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	HeapNode heapNode[n-1];
	for(int i = 1; i < n; i++) {
		heapNode[i-1].l = a[i-1];
		heapNode[i-1].r = a[i];
		heapNode[i-1].diff = heapNode[i-1].r - heapNode[i-1].l; 
	}
	        int m  = n-1;

	Build_Max_Heap(heapNode,n-1);

	for(int i = 0; i < k; i++) {
		insertAverage(heapNode,m);
		m ++;
	}
	printf("%d",heapNode[0].diff);

	return 0;
}