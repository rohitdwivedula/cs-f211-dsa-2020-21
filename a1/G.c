#include <stdio.h>
#include <stdlib.h>
#define N 500

int adj[N][N];
int vis[N], sizes[N];
int pos;

void DFS(int n, int src)
{
    vis[src] = 1;
    sizes[pos]++;
    for(int i = 0; i < n; i++)
        if(adj[src][i] && !vis[i])
            DFS(n, i);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    for(int i = 0; i < n; i++)
        if(!vis[i])
        {
            DFS(n, i);
            pos++;
        }

    printf("%d\n", pos);
    for(int i = 0; i < pos; i++)
        printf("%d ", sizes[i]);
    return 0;
}