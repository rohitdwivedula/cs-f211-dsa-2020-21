#include<stdio.h>
#include<stdlib.h>

int **createWeightedAdjM(int V, int E){
    int **adjM = (int **)malloc(sizeof(int *) * V);
    for(int i = 0; i < V; ++i){
        adjM[i] = (int *)malloc(sizeof(int) * V);
    }

    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adjM[u][v] = w;
        adjM[v][u] = w;
    }

    return adjM;
}

int minKey(int MST_set[], int key[], int N){
    int min = 99999, minIdx;

    for(int i = 0; i < N; ++i){
        if(MST_set[i] == 0 && key[i] < min){
            min = key[i];
            minIdx = i;
        }
    }

    return minIdx;
}

int prim(int N, int M, int **adjM){
    int P[N], key[N], MST_set[N];

    for(int i = 0; i < N; ++i){
        key[i] = 99999;
        MST_set[i] = 0;
    }

    key[0] = 0;
    P[0] = -1;

    for(int i = 0; i < N - 1; ++i){
        int idx = minKey(MST_set, key, N);
        MST_set[idx] = 1;

        for(int j = 0; j < N; ++j){
            if(adjM[idx][j] && MST_set[j] == 0 && adjM[idx][j] < key[j]){
                P[j] = idx; key[j] = adjM[idx][j];
            }
        }
    }
    int minCost = 0;
    for(int i = i; i < N; ++i){
        minCost += adjM[i][P[i]];
    }
    return minCost;
}


int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int **adjM = createWeightedAdjM(N, M);
    printf("%d", prim(N, M, adjM));
}