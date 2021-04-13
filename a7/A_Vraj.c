#include<stdio.h>
#include<stdlib.h>
#define N 1000
 
int n, top=-1;
 
struct element{
    int index;
    int value;
};
 
 
void read_and_solve(){
    scanf("%d", &n);
    struct element* e = (struct element*)malloc(n*sizeof(int)*sizeof(struct element));
    struct element* stack = (struct element*)malloc(n*sizeof(int)*sizeof(struct element));
    for(int i=0;i<n;i++){
        int v;
        scanf("%d", &v);
        e[i].index = i+1;
        e[i].value = v;
    }
 
    ++top;
    stack[top] = e[n-1];
    for(int i=n-2;i>=0;i--){
 
        if(top==-1){
            ++top;
            stack[top] = e[i];
            continue;
        }
 
        while(top!=-1 && stack[top].value>e[i].value){
            e[stack[top].index-1].index = e[i].index;
            --top;
        }

        ++top;
        stack[top] = e[i];
    }
 
    while(top!=-1){
        e[stack[top].index-1].index=-1;
        --top;
    }
 
    for(int i = 0;i<n;i++)printf("%d ", e[i].index);
}
 
 
 
int main(){
    read_and_solve();
    return 0;
}