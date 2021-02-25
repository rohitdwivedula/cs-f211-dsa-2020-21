#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define edge struct edge


edge{
    int u;
    int v;
    int weight;
};

void merge(edge* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    edge* L = (edge*)malloc(sizeof(edge) * n1);
    edge* R = (edge*)malloc(sizeof(edge) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].weight <= R[j].weight) {
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
void mergeSort(edge* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int* parent;

int findParent(int node)
{
    if(parent[node] == node)
        return parent[node];
    parent[node] = findParent(parent[node]);
    return parent[node];
}

void link(int i , int j)
{
    int i_parent = findParent(i);
    int j_parent = findParent(j);
    parent[j_parent] = i_parent; // parent[i_parent] = j_parent;
}

int main()
{
    int n , m;
    scanf("%d %d%*c" , &n , &m);

    parent = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++)
        parent[i] = i;

    edge* graphs = (edge*)malloc(sizeof(edge) * m);
    for (int i = 0; i < m; i++)scanf("%d %d %d%*c" ,&graphs[i].u , &graphs[i].v , &graphs[i].weight);
    mergeSort(graphs , 0 , m-1);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if(findParent(graphs[i].u) == findParent(graphs[i].v))
            continue;
        else{
            ans += graphs[i].weight;
            link(graphs[i].u , graphs[i].v);
        }
    }
    printf("%d" , ans);
}
