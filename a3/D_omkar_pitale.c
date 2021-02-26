#include<stdio.h>

void swap(long *a, long *b){
     long t = *a;
    *a = *b;
    *b = t;
}

int partition(long *arr, int L, int H){
    int pivot = arr[H];
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(arr[i] < pivot){
            pIdx++;
            swap(&arr[pIdx], &arr[i]);
        }
    }
    swap(&arr[pIdx + 1], &arr[H]);
    return pIdx + 1;
}

void qSort(long *arr, int L, int H){
    if(L < H){
        int pIdx = partition(arr, L, H);
        qSort(arr, L, pIdx - 1);
        qSort(arr, pIdx + 1, H);
    }
}

void subArrs(int n, long *a, long *b){
    for(int i = 0; i < n; ++i){
        a[i] = a[i] - b[i];
    }
}

int goodPairs(long *x, long *y, int n, int k1, int k2){
    subArrs(n, x, y);
    qSort(x, 0, n - 1);


    int pairs = 0, p1 = 0, p2 = n - 1;

    while(p1 < p2){
        if(x[p1] + x[p2] > k2 - k1){
            pairs += p2 - p1;
            p2--;
        }
        else{
            p1++;
        }
    }
    return pairs;
}

int main(){
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);
    long a[n], b[n];

    for(int i = 0; i < n; ++i){
        scanf("%ld", &a[i]);
    }

    for(int i = 0; i < n; ++i){
        scanf("%ld", &b[i]);
    }

    printf("%d", goodPairs(a, b, n, k1, k2));
}
