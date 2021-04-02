#include <stdio.h>
int l = 0, r = 0;
int median = 0;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void maxHeapify(int left[], int i) {
	int parent = (i-1)/2;
	if(i >= 0 && left[parent] < left[i]) {
		swap(&left[parent], &left[i]);
		maxHeapify(left, parent);
	}

}

void minHeapify(int right[], int i) {
	int parent = (i-1)/2;
	if(i >= 0 && right[parent] > right[i]) {
		swap(&right[parent], &right[i]);
		minHeapify(right, parent);
	}
}
int findMedian(int x, int left[], int right[], int median) {
	if(l > r) {
		if(x < median) {
			right[r] = left[0];
			r++;
			minHeapify(right, r-1);
			left[0] = x;
			swap(&left[0],&left[l-1]);
			maxHeapify(left, l-1);
		} else {
			right[r] = x;
			r++;
			minHeapify(right, r-1);
		}
		return (left[0]+right[0])/2;
	} else if(l == r) {
		if(x < median) {
			left[l] = x;
			l++;
			maxHeapify(left, l-1);
			return left[0];
		} else {
			right[r] = x;
			r++;
			minHeapify(right, r-1);
			return right[0];
		}
	} else {
		if(x < median) {
			left[l] = x;
			l++;
			maxHeapify(left, l-1);
		} else {
			left[l] = right[0];
			l++;
			maxHeapify(left, l-1);
			right[0] = x;
			swap(&right[0],&right[r-1]);
			minHeapify(right, r-1);
		}
		return (left[0]+right[0])/2;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	int a[n], left[(n+1)/2], right[(n+1)/2];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		median = findMedian(a[i], left, right, median);
		printf("%d ",median);
	}
}