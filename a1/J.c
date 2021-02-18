#include <stdio.h>
#include <stdlib.h>
#define N 500

int adj[N][N];
int vis[N];
char colors[N];

int BFS(int n, int src)
{
    int queue[n * n];
    int front = 0, back = 0;

    vis[src] = 1;
    queue[back++] = src;
    while(front != back)
    {
        int u = queue[front++];
        for(int i = 0; i < n; i++)
            if(adj[u][i])
            {
                if(vis[i] == -1)
                {
                    vis[i] = !vis[u];
                    queue[back++] = i;
                }
                else if(vis[i] == vis[u])
                    return 0;
            } 
    }

    for(int i = 0; i < n; i++)
        colors[i] = (vis[i] ? 'R' : 'B');
    return 1;
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
        vis[i] = -1;

    printf("%s", (BFS(n, 0) ? colors : "NEED MORE COLOURS"));
    return 0;
}