#include <stdio.h>
#include <stdlib.h>
//get back to this later
//stack implementation
struct stack{
    int* data;
    int top;
};

void pop(struct stack* s){
    s->top--;
}

int top(struct stack* s){
    return s->data[s->top];
}

void push(int n, struct stack* s){
    s->top++;
    s->data[s->top]=n;
}

int empty(struct stack* s){
    if(s->top==-1) return 1;
    return 0;
}


//function to create minimum array
void minarray(int n, int a[]){
    int area, max=0, temp, i;
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->data=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        while(!empty(s) && a[top(s)]>a[i]){
            temp=top(s);
            pop(s);
            if(empty(s)) area=a[temp]*i;
            else area=a[temp]*(i-top(s)-1);
            if(max<area) max=area;

        }
        if(empty(s) || a[top(s)]<=a[i]){
            push(i,s);
        }
    }
    while(!empty(s)){
        temp=top(s);
        pop(s);
        if(empty(s)) area=a[temp]*i;
        else area=a[temp]*(i-top(s)-1);
        if(max<area) max=area;
    }
    printf("%d", max);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    minarray(n,a);
    return 0;
}
