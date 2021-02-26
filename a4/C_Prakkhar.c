#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

char** dictionary;
int n;

bool** graph;
bool* visited;

bool* used;

bool compatible(char* A , char* B)
{
    int count = 0;
    int len = strlen(A);
    rep(i,len)count += (A[i] != B[i]);
    return count == 1;
}

int getPos(char* A , char* B)
{
    int pos = -1;
    int len = strlen(A);
    rep(i,len)if(A[i] != B[i])return i;
    return -1;
}

void buildGraph()
{
    graph = (bool**)malloc(sizeof(bool*) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    rep(i,n){
        graph[i] = (bool*)malloc(sizeof(bool) * n);
        visited[i] = false;
    }
    rep(i,n){
        rep(j,n){
            graph[i][j] = compatible(dictionary[i] , dictionary[j]);
        }
    }
}

bool check(int node , int source_len)
{
    if(visited[node])
        return false;
    visited[node] = true;
    bool ok = false;
    rep(i,n)
    {
        if(graph[node][i] && !visited[i])
        {
            int pos = getPos(dictionary[node] , dictionary[i]);
            if(!used[pos])
            {
                used[pos] = true;
                int count = 0;
                rep(j,source_len)count += used[j];
                if(count == source_len)
                {
                    ok = true;
                    //printf("%s " , dictionary[i]);
                    break;
                }
                ok = ok | check(i , source_len);
                if(ok)
                {
                    //printf("%s " , dictionary[i]);
                    break;
                }
                used[pos] = false;
            }
        }
    }
    return ok;
}

int main()
{
    scanf("%d%*c" , &n);
    n++;
    dictionary = (char**)malloc(sizeof(char*) * n);
    char S[20];
    scanf("%s%*c", S);
    dictionary[0] = (char*)malloc(sizeof(char) * 20);
    strcpy(dictionary[0] , S);
    int source_len = strlen(dictionary[0]);
    used = (bool*)malloc(sizeof(bool) * source_len);
    rep(i,source_len)used[i] = false;
    int j = 1;
    rep(i,n-1)
    {
        char temp[20];
        scanf("%s%*c" , temp);
        if(strlen(temp) == source_len)
        {
            dictionary[j] = (char*)malloc(sizeof(char) * 20);
            strcpy(dictionary[j] , temp);
            j++;
        }
    }
    n = j;
    buildGraph();
    // rep(i,j)
    // printf("%s\n" , dictionary[i]);
    if(check(0 , source_len))printf("%d" , source_len - 1);
    else printf("-1");
}   
