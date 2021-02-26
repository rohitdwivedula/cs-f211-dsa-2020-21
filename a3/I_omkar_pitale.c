#include<stdio.h>
#include<math.h>

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

int suitableIdx(int n, int *arr, int key){
    int idx, f = 1;
    if(key <= 0){
        return idx = 0;
    }
    for(int i = 0; i < n && f; ++i){
        if(arr[i] <= key){
            idx = i;
        }
        else{
            f = 0;
        }
    }
    if(key == arr[idx])
        return idx;
    else 
        return idx + 1;
}

int minCost(int *tollGates, int *gasContainers, int n, int m, int l, int s, int d, double a, double b, int k){
    qSort(tollGates, 0, m - 1);
    qSort(gasContainers, 0, l - 1);
    int cost = 0;
    int sIdx = suitableIdx(m, tollGates,s);
    int dIdx = suitableIdx(m, tollGates, d);

    for(int i = sIdx; i < dIdx; ++i){
        int reqFuel = ceil(((tollGates[i + 1] - tollGates[i]) - b) / a);
        cost += gasContainers[suitableIdx(l, gasContainers, reqFuel)] * k;
    }
    return cost;
}


int main(){
    int n, m, l, u, v, a, b, k;
    scanf("%d %d %d", &n, &m, &l);
    scanf("%d %d %d %d %d", &u, &v, &a, &b, &k);
    int tollGates[m], gasContainers[l];

    for(int i = 0; i < m; ++i){
        scanf("%d", &tollGates[i]);
    }
    for(int i = 0; i < l; ++i){
        scanf("%d", &gasContainers[i]);
    }

    printf("%d", minCost(tollGates, gasContainers, n, m, l, u, v, a, b, k));
}