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

int choices(int n, int m, int cost[], int money[]){
    qSort(cost, 0, m - 1);
    int choiceList[n];
    for(int i = 0; i < n; ++i){
        int f = 1;
        for(int j = m - 1; j >= 0 && f; --j){
            if(money[i] >= cost[j]){
                choiceList[i] = j + 1;
                f = 0;
            }
        }
        if(f)
            choiceList[i] = 0;
    }

    for(int i = 0; i < n; ++i){
        printf("%d ", choiceList[i]);
    }
}


int main(){
    int n, m;
    scanf("%d %d", &m, &n);
    int cost[m], money[n];

    for(int i = 0; i < m; ++i){
        scanf("%d", &cost[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &money[i]);
    }

    choices(n, m, cost, money);
}