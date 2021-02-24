#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//http://p.ip.fi/QCHV
bool visited[1005];
int V;
int adj[1005][1005];
int n;
int DFS(int i)
{
    int j;
    int count=1;
//	printf("\n%d",i);
    visited[i]=true;
	
	for(j=1;j<=n;j++)
    {
         if(!visited[j]&&adj[i][j]==1)
         { 
            count+=DFS(j);
         }
    }
    return count;
}
int main()
{
    int m;
    scanf("%d %d",&n,&m);
    int u,v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        
    }
    int curr;
    int islands=0;
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            curr=DFS(i);
            islands=curr>islands ? curr : islands;
        }
        
    }
    printf("%d",islands);
    
}