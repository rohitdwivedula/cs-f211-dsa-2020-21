#include<stdio.h>

#define N 10001

long long memo[N];

long long compute(int n)
{
    if(memo[n] != -1)return memo[n];
    if(n & 1){
        return memo[n] = compute(n - 1);
    }else return memo[n] = (compute(n-1) + compute(n/2));
}

int main()
{
    for(int i = 0 ; i < N ; i++)
        memo[i] = -1;
    memo[1] = 1;
    memo[0] = 0;
    int n;
    scanf("%d" , &n);
    printf("%lld" , compute(n));
}
