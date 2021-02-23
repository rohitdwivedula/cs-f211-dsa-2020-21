#include<stdio.h>

const int N = 1e5 + 5;
int memo[100005];

int min(int a , int b){
    if(a < b)return a;
    else return b;
}

int f(int n){
    if(memo[n] != -1)return memo[n];
    int count = 0;
    int a = n;
    int b = n;
    for(int i = 2; i*i <= n ; i++){
        if(n%i == 0){
            if(count == 0){
                a = i;
                count++;
                if(n/i != i){
                    b = n/i;
                    count++;
                }
            }
            else if(count == 1){
                b = i;
                count += 1;
            }else if(count == 2){
                b = min(b , i);
            }   
        }
    }
    if(count <= 1)return memo[n] = n;
    memo[n] = f(n/a) + f(n/b);
    return memo[n];
}

int main()
{
    for(int i = 0 ; i < N ; i++){
        memo[i] = -1;
    }
    int n;
    scanf("%d" , &n);
    printf("%d"  , f(n));

}
