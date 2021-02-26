#include <stdio.h>

int main(){
    int n;
    scanf("%d" , &n);
    long long int ans = 0;
    int level = 1;
    int nextLevel = 2;
    int x;
    for(int i = 1; i <= n; i++)
    {
        if(nextLevel == i)level += 1 , nextLevel *= 2;
        scanf("%d" , &x);
        ans += (long long int)level * x;
    }
    printf("%d" , ans);
}
