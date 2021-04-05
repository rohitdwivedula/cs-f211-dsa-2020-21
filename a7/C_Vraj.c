#include <stdio.h>
int A[1000][1000];
int stack[1000000];
int top = -1, n, m;
int isempty() {
   if(top == -1)  return 1;
   else  return 0;
}
int peek() {
   return stack[top];
}
int pop() {
    int data;
    data = stack[top];
    top = top - 1;
    return data;
}
void push(int data) {
    top = top + 1;
    stack[top] = data;
    return;
}
int maxHist(int row[]){
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < m) {
        if (isempty() || row[peek()] <= row[i])    push(i++);
        else {
            top_val = row[peek()];
            pop();
            area = top_val * i;
            if (!isempty())  area = top_val * (i - peek() - 1);
            if(area>max_area) max_area = area;
        }
    }
    while (!isempty()) {
        top_val = row[peek()];
        pop();
        area = top_val * i;
        if (!isempty())  area = top_val * (i - peek() - 1);
        if(area>max_area) max_area = area;
    }
    return max_area;
}
int maxRectangle(int A[][1000]){
    int result = maxHist(A[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (A[i][j])    A[i][j] += A[i - 1][j];
        }
        if(result<maxHist(A[i])) result = maxHist(A[i]);
    }
    return result;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }       
    }
    printf("%d",maxRectangle(A));
    return 0;
}