#include <stdio.h>
#include <stdlib.h>
//stack implementation
struct stack{
    int* data;
    int top;
};

int empty(struct stack* s){
    if(s->top==-1) return 1;
    return 0;
}

void pop(struct stack* s){
    s->top--;
}

int top(struct stack* s){
    if(s->top==-1) return -1;
    return s->data[s->top];
}

void push(int n, struct stack* s){
    s->top++;
    s->data[s->top]=n;
}
//function which prints index of closest smaller integer to the left

void answer(int a[], int n){
    struct stack* s = (struct stack *)malloc(sizeof(struct stack));
    s->data=(int*)malloc(n*sizeof(int));
    s->top=-1;
    for(int i=0;i<n;i++){
        while(!empty(s) && a[top(s)-1]>=a[i]){
            pop(s);
        }
        if(empty(s)){
            printf("-1");
        }
        else{
            printf("%d",top(s));
        }
        push(i+1,s);
        if(i!=n-1) printf(" ");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    answer(a,n);
    return 0;
}
