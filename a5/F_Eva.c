#include <stdio.h>
#include <stdlib.h>

void dfsrecur(int v, int n, int a[][n], int visited[]){
    printf("%d ", v+1);
    visited[v]=1;
    for(int i=0; i<n; i++){
        if(a[v][i]==1 && visited[i]==0)
            dfsrecur(i,n,a,visited);
    }
}

void dfs(int n, int a[][n]){
    int visited[n];
    memset(visited,0,n*sizeof(int));
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfsrecur(i,n,a,visited);
    }
}

int main()
{
    int n,m,i;
    scanf("%d %d", &n,&m);
    int a[n][n];
    for(i=0;i<n;i++)
        memset(a[i],0,n*sizeof(int));
    int p,q;
    for(i=0;i<m;i++){
        scanf("%d %d",&p,&q);
        a[p-1][q-1]=1;
        a[q-1][p-1]=1;
    }
    dfs(n,a);
    return 0;
}
