#include<stdio.h>
#include<stdlib.h>

/**
 * This question is actually a tree-based question despite appearances.
 * 
 * If we draw a map with arrows depicting one person winning against another,
 * we can observe that
 * a) the missing pair is the only pair of numbers that is not directly connected.
 * b) the person in that pair who won is determined easily, as if a cycle is formed
 *    by making a person win over the other, it means that is not the person that won.
 * 
 * For example, take the test case
 * 3
 * 3 2
 * 2 1
 * 
 * Clearly, in the map (3)->(2)->(1), the nodes 3 and 1 are not directly connected.
 * If we make the edge (1)->(3), we make a cycle. Since 3 beats 2 and 2 beats 1,
 * 1 certainly cannot beat 3. Therefore the correct pair is 3 1.
 * 
 * **/ 


int n,m;

int dfs(int*,int);
int mkd[2000];

void main(){
    
    scanf("%d",&n);

    int* adj = (int*) malloc(n*n*sizeof(int));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[n*i+j] = 0;

    m = n*(n-1)/2 - 1;

    for(int i = 0; i < m; i++){
        int u,v;
        scanf(" %d %d",&u,&v);
        adj[n*(u-1)+(v-1)] = 1;
    }

    // missing pair nodes
    int lu, lv;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            //Check for missing connection
            if((i!=j) && (adj[n*i+j]==0) && (adj[n*j+i]==0)){
                lu = i;
                lv = j;
            }
        }

    //test if lu winning over lv makes a cycle
    adj[n*lu+lv] = 1;

    for(int i = 0; i < n; i++) mkd[i] = 0;
    int cyclechk = dfs(adj,lu);

    //if cycle is formed, the reversed edge is correct
    if(cyclechk==1) printf("%d %d",lv+1,lu+1);
    else printf("%d %d",lu+1,lv+1);

}

int dfs(int* adj,int x){
    
    mkd[x] = 0;

    for(int i = 0; i < n; i++){
        if(adj[n*x+i]==1){
            if(mkd[i]==1)
                return 1;
            else
                return dfs(adj,i);
        }
    }

    return 0;

}