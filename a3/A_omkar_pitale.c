#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int L, int H){
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

void qSort(int *arr, int L, int H){
    if(L < H){
        int pIdx = partition(arr, L, H);
        qSort(arr, L, pIdx - 1);
        qSort(arr, pIdx + 1, H);
    }
}

int maxIceCreams(int *S, int *A, int n, int m, int k){
    qSort(S, 0, m - 1);
    qSort(A, 0, n - 1);

    int max = 0, i = 0, j = 0;

    while(i < n && j < m){
        if(A[i] - k <= S[j] && S[j] <= A[i] + k){
            i++;
            j++;
            max++;
        }
        else if (A[i] - S[j] > 0){
            j++;
        }
        else if (A[i] - S[j] < 0){
            i++;
        }
    }
    return max;
}


int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int S[n], A[m];

    for(int i = 0; i < n; ++i){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &S[i]);
    }

    printf("%d", maxIceCreams(S, A, n, m, k));
}