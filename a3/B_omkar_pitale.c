#include<stdio.h>
#include<stdlib.h>

void assasinStats(int n, int m, int *A, int *B, int *G){
    
    int *assasinGold = (int *)calloc(n, sizeof(int));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(A[i] >= B[j]){
                assasinGold[i] += G[j];
            }
        }
        printf("%d ", assasinGold[i]);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int A[n], B[m], G[m];

    for(int i = 0; i < n; ++i){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < m; ++i){
        scanf("%d %d", &B[i], &G[i]);
    }

    assasinStats(n, m, A, B, G);
}