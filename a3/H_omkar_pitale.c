#include<stdio.h>
#include<stdlib.h>

int **createAdjM(int V, int E){
    int **adjM = (int **)malloc(V * sizeof(int *));

    for(int i = 0; i < V; ++i){
        adjM[i] = (int *)malloc(V * sizeof(int));
    }

    for(int i = 0; i < E; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        adjM[u][v] = 1;
    }
    return adjM;
}

int **citationList(int *authors, int a){
    int **citation = (int **)malloc(sizeof(int *) * a);
    for(int i = 0; i < a; ++i){
        citation[i] = (int *)malloc(sizeof(int) * authors[i]);
    }

    return citation;
}

int hIdx(int **citation, int *author, int a){
    int n = author[a];
    int *bucket = (int *)malloc(sizeof(int) * (n + 1));

    for(int i = 0; i < n; ++i){
        int x = citation[a][i];
        if(x >= n){
            bucket[n]++;
        }
        else{
            bucket[x]++;
        }
    }

    int count = 0;
    for(int i = n; i >= 0; --i){
        count += bucket[i];
        if(count >= i)
            return i;
    }
    return 0;
}

void hIndex(int a, int p, int c, int *authors, int *publications){
    int **adjM = createAdjM(p, c);
    int **citation = citationList(authors, a);
    int *idx = (int *)calloc(a, sizeof(int));
    
    for(int i = 0; i < p; ++i){
        int inDegree = 0;
        for(int j = 0; j < p; ++j){
            if(adjM[j][i] == 1){
                inDegree++;
            }
        }
        citation[publications[i]][idx[publications[i]]] = inDegree;
        idx[publications[i]]++;
    }

    for(int i = 0; i < a; ++i){
        printf("%d ", hIdx(citation, authors, i));
    }
}


int main(){
    int a, p, c;
    scanf("%d %d %d", &a, &p, &c);
    int *authors = (int *)calloc(a, sizeof(int));
    int publications[p];

    for(int i = 0; i < p; ++i){
        int u;
        scanf("%d", &u);
        publications[i] = u;
        authors[u]++; 
    }

    hIndex(a, p, c, authors, publications);
}