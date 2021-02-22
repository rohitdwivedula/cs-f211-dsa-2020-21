#include<stdio.h>
#include<stdlib.h>

void dfs(int*,int);

int mkd[1000];
int max;
int n,m;

void main(){

    scanf(" %d %d",&n,&m);

    int* adj = (int*) malloc (n*n*sizeof(int));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[m*i+j] = 0;

    for(int i = 0; i < m; i++){
        int u,v;
        scanf(" %d %d",&u,&v);
        adj[n*(u-1)+(v-1)]=1;
    }

    max = 0;
    for(int i = 0; i < n; i++){
        for(int i = 0; i < n; i++) mkd[i] = 0;
        dfs(adj,i);

        int temp = 0;
        for(int i = 0; i < n; i++) if(mkd[i]==1) temp++;
        if(temp>max) max = temp;
    }

    printf("%d",max);

}

void dfs(int* adj, int x){
    mkd[x] = 1;

    for(int i = 0; i < n; i++){
        if(adj[n*x+i]==1 && mkd[i]==0)
                dfs(adj,i);
    }

}