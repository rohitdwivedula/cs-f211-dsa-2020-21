#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
int partition(float a[], int b[], int low, int high) {
    float pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
	if(a[j] < pivot) {
	    i++;
	    swap1(&a[i],&a[j]);
	    swap(&b[i],&b[j]);
	}
    }
    swap1(&a[i+1],&a[high]);
    swap(&b[i+1],&b[high]);
    return (i+1);
}
void quicksort(float a[], int b[], int low, int high) {
    if(low < high) {
	int pivot = partition(a,b,low,high);
	quicksort(a,b,low,pivot-1);
	quicksort(a,b,pivot+1,high);
    }
    return;
}
int main() {
    int n, e, s;
    scanf("%d %d %d",&n,&e,&s);
    float a[n] , b[n], c[n], prob[n];
    memset(a,-1,n*sizeof(int));
    memset(b,0,n*sizeof(float));
    memset(c,0,n*sizeof(float));
    a[s] = -1;b[s]=1;
    for(int i = 0; i < e; i++) {
	   int x,y;
	   float p;
	   scanf("%d %d %f",&x,&y,&p);
	   a[y] = x;
	   b[y] = p;
	   c[x] += p;
    }
    int idx[n];
    for(int i = 0; i < n; i++) {
	idx[i] = i;
	int j = i; 
	float cnt=1;

    // Iterating upto the leaf node
	while(a[j] != -1) {
		cnt *= b[j];
		j = a[j];
	}   
        prob[i] = cnt*(1-c[i]);
    }

    quicksort(prob,idx,0,n-1);

    for(int i = n-1; i >= 0; i--) {
	printf("%d ",idx[i]);
    }

    return 0;
}
