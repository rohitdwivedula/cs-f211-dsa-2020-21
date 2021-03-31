#include <stdio.h>
#define abs(a) (a>0 ? a : -a)

int k = 1, sum = 0;
void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 
void Max_Heapify(int cost[], int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && cost[i] < cost[l]) 
		largest = l;

	if(r < n && cost[i] < cost[r])
		largest = r;

	if(largest != i) {
		swap(&cost[i],&cost[largest]);
		Max_Heapify(cost, n, largest);
	}

	return;
	
}
void Min_Heapify(int cost[], int n, int i) {
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && cost[i] > cost[l]) 
		smallest = l;

	if(r < n && cost[i] > cost[r])
		smallest = r;

	if(smallest != i) {
		swap(&cost[i],&cost[smallest]);
		Min_Heapify(cost, n, smallest);
	}

	return;
	
}

void Build_Min_Heap(int a[], int n) {

	int start = n/2 - 1;

	for(int i = start; i >= 0; i--) {
		Min_Heapify(a, n, i);
	}

	return;                                                                                       
}

void Build_Max_Heap(int b[], int n) {

	int start = n/2 - 1;

	for(int i = start; i >= 0; i--) {
		Max_Heapify(b, n, i);
	}

	return;                                                                                       
}


void fun(int a[], int b[], int n, int ans[], int sum) {
	ans[k++] = sum - 2*a[0];
	sum -= 2*a[0];
	a[0] = abs(b[0]-a[0]);
	b[0] = abs(b[0]-a[0]);
	Max_Heapify(b,n-1,0);
	Min_Heapify(a,n-1,0);
	return; 
}
int main() {
	int n,q;
	scanf("%d %d",&n,&q);

	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
		b[i] = a[i];
	}

	Build_Min_Heap(a,n);
	Build_Max_Heap(b,n);
        
        int m = n, ans[n];
	for(int i = 1; i < n; i++) {
		fun(a,b,m,ans,sum);
		m--;
	}
	for(int i = 0; i < q; i++) {
		int x;
		scanf("%d",&x);
		printf("%d",ans[x]);
	}

	return 0;
}