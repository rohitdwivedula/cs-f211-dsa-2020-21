#include <stdio.h>
#include <stdlib.h>

int lsum=0;
int rsum=0;
int maxlevel=0;

int abs(int n){
    if(n<0) return -1*n;
    return n;
}

void rightview(int i, int level, int n, int a[]){
    if(i>=n) return;
    if(a[i]==-1)
        return;
    if (maxlevel<level){
        rsum+=a[i];
        maxlevel=level;
    }
    rightview(2*i+2, level + 1, n, a);
    rightview(2*i+1, level + 1, n, a);
}


void leftview(int i, int level, int n, int a[]){
    if(i>=n) return;
    if(a[i]==-1)
        return;
    if (maxlevel<level){
        lsum+=a[i];
        maxlevel=level;
    }
    leftview(2*i+1, level+1, n, a);
    leftview(2*i+2, level+1, n, a);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    leftview(0,1, n, a);
    maxlevel=0;
    rightview(0,1, n, a);
    printf("%d", rsum);
    return 0;
}
