#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 1000


int min(int x,int y){
    if(x>y)return y;
    return x;
}

int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    int arr[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d", &arr[i][j]);
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)a[i][j] = n+1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < m; l++) {
                    if (arr[k][l] == 1)a[i][j] = min(a[i][j],abs(i-k) + abs(j-l));
                }
            }
        }
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m-1; j++){
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][m-1]);
    }
    for(int i = 0; i < m-1; i++){
        printf("%d ",a[n-1][i]);
    }
    printf("%d",a[n-1][m-1]);
}