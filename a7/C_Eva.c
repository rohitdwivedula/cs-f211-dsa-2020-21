#include <stdio.h>
#include <stdlib.h>
//stack implementation
struct stack{
    int* data;
    int top;
};

int empty(struct stack* s){
    return (s->top==-1);
}

int top(struct stack* s){
    return s->data[s->top];
}

void pop(struct stack* s){
    s->top--;
}

void push(int n, struct stack* s){
    s->top++;
    s->data[s->top]=n;
}

//calculating maximum rectangle for each row
int maxarea(int n, int a[]){
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
    return max;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d", &a[i][j]);
    int max=maxarea(m, a[0]);
    int area;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=0) a[i][j]+=a[i-1][j];
        }
        area=maxarea(m,a[i]);
        if(area>max) max=area;
    }
    printf("%d", max);
    return 0;
}
