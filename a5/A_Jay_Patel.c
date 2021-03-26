#include<stdio.h>

typedef struct {
	int time;
	int priority;
	int idx;
} HeapNode;

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 
void Heapify(HeapNode heapNode[], int n, int i) {
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && heapNode[smallest].priority > heapNode[l].priority) 
		smallest = l;

	if(r < n && heapNode[smallest].priority > heapNode[r].priority)
		smallest = r;

	if(l < n && heapNode[smallest].priority == heapNode[l].priority) {
		if(heapNode[smallest].time > heapNode[l].time) {
			smallest = l;
		}
	}

	if(r < n && heapNode[smallest].priority == heapNode[r].priority) {
		if(heapNode[smallest].time > heapNode[r].time) {
			smallest = r;
		}
	}

	if(smallest != i) {
		swap(&heapNode[i].time, &heapNode[smallest].time);
		swap(&heapNode[i].priority, &heapNode[smallest].priority);
		swap(&heapNode[i].idx, &heapNode[smallest].idx);

		Heapify(heapNode, n, smallest);
	}

	return;
	
}

void Build_Heap(HeapNode heapNode[], int n) {

	int start = n/2 - 1;

	for(int i = start; i >= 0; i--) {
		Heapify(heapNode, n, i);
	}

	return;                                                                                       
}

int AssignTask(HeapNode heapNode[], int k) {
	int assigned = heapNode[0].idx;
	heapNode[0] = heapNode[k-1];
	Heapify(heapNode, k-1, 0);
	return assigned;
}

int main() {

	int t,k;
	scanf("%d %d",&t,&k);
        
        HeapNode heapNode[t];
        for(int i = 0; i < t; i++) {
        	scanf("%d %d",&heapNode[i].time,&heapNode[i].priority);
        	heapNode[i].idx = i;
        } 
        int m = t;
        Build_Heap(heapNode,t);
        for(int i = 0; i < k; i++) {
        	printf("%d ",AssignTask(heapNode,m));
        	m--;    	
        }

	return 0;
}