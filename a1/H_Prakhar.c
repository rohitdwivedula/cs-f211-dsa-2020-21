#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long long max(long long a , long long b){
    if(a > b)return a;
    return b;
}

long long min(long long a , long long b){
    if(a < b)return a;
    return b;
}

int main(){
    int n;
    scanf("%d" , &n);
    int* sq = (int*)malloc(sizeof(int) * n);
    int* cu = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &sq[i]);
        cu[i] = sq[i] * sq[i] * sq[i];
        sq[i] *= sq[i];
    }
    long long minCost = LONG_LONG_MAX;
    long long maxCost = LONG_LONG_MIN;
    for(int i = 0 ; i < n ; i++){
        int start = i;
        long long temp = 0;
        for(int j = 0 ; j < n ; j++){
                if(j & 1){
                    temp -= cu[start];
                }else{
                    temp += sq[start];
                }
                start += 1 , start %= n;
        }
        maxCost = max(maxCost , temp);
        minCost = min(minCost , temp);

    }
    printf("%d" , maxCost - minCost);
    return 0;
}
