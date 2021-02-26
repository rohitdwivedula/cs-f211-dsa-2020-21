#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* A;
int* S;
int n,m,k;

void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    scanf("%d %d %d%*c" , &n, &m , &k);
    A = (int*)malloc(sizeof(int) * n);
    S = (int*)malloc(sizeof(int) * m);
    for(int i = 0 ; i < n ; i++)
        scanf("%d%*c" , &A[i]);
    for(int i = 0 ; i < m ; i++)
        scanf("%d%*c" , &S[i]);
    mergeSort(A , 0, n-1);
    mergeSort(S , 0, m-1);
    int ans = 0;
    int child = 0;
    for (int i = 0; i < m; i++)
    {
        while(child < n)
        {
            int lower = A[child]- k;
            int upper = A[child] + k;
            if(S[i] < lower)break;
            if(S[i] >= lower && S[i] <= upper)
            {
                ans++;
                child++;
                break;
            }
            child++;
        }
    }
    printf("%d" , ans);
}
