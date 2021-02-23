#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int count[2005];
int front[2005];
int back[2005];
bool visited[2005];
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
int main()
{
    int n;
    scanf("%d",&n);
    int u,v;
    for (int i = 1; i < (n*(n-1))/2; i++)
    {
        scanf("%d %d",&u,&v);
        front[u]++;
        back[v]++;
        count[u]++;
        count[v]++;
       
    }
    
    int first=0,second=0;
    for (int i = 1; i <= n; i++)
    {
        if(front[i]+back[i]<(n-1))
        {
            if(!first)
            first=i;
            else
            second=i;
        }
        else
        {
            visited[front[i]+1]=true;
        }
    }
    if(visited[front[first]+1] && !visited[front[first]+2])
    {
        int pos_first=front[first]+2;
        int pos_second=front[second]+1;
        if(pos_first<pos_second)
        {
            swap(&first,&second);
        }
    }
    else if(!visited[front[first]+1] && visited[front[first]+2])
    {
        int pos_first=front[first]+1;
        int pos_second=front[second]+2;
        if(pos_first<pos_second)
        {
            swap(&first,&second);
        }

    }
    printf("%d %d",first,second);
    
    
    return 0;
}