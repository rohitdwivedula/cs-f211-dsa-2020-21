#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int M,N;
    scanf("%d%d" , &M , &N);
    int* costs = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N ; i++)
    {
        scanf("%d" , &costs[i]);
    }
    int lim = 1 << N;
    int i = 0;
    int ans = 0;
    while(i < lim){
        long long  cost = 0;
        int temp = 0;
        for(int bit = 1 ; bit <= N ; bit++){
            bool set = i & (1 << (bit-1));
            temp += set;
            cost += set ? costs[bit-1] : 0;
        }
        if(cost <= M){
            if(temp > ans)ans = temp;
        }
        i++;
    }
    printf("%d" , ans);
    return 0;
}
