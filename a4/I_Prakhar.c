#include <stdio.h>

const  int MOD = 1e9 + 7;

int pos;
int big , small , x;

long long fact(int n)
{
    if(n <= 1)return 1LL;
    long long ans = 1LL;
    for(int i = 1; i <= n; i++)
        ans *= (long long)i , ans %= (long long)MOD;
    return ans;
}

long long get(int l , int r)
{
    long long ways = 1LL;
    int mid = (l+r) / 2;
    int newL , newR;
    //printf("%lld %lld %lld\n" , l , r , mid);
    if(mid == pos){
        ways *= 1LL;
        newL = mid+1;
        newR = r;
    }
    if(mid > pos){
        ways *= (long long)(big--) , ways %= (long long)MOD;
        newL = l;
        newR = mid;
    }
    if(mid < pos){
        ways *= (long long)(small--) , ways%= (long long)MOD;
        newL = mid+1;
        newR = r;
    }
    if(newL < newR)ways *= (long long)get(newL , newR) , ways%= (long long)MOD;
    return ways;
}

int main()
{
    int n;
    scanf("%d %d %d" , &n , &x , &pos);
    big = n - x;
    small = x-1;
    long long ans = get(0,n);
    ans *= fact(small+big) , ans %= (long long)MOD;
    printf("%lld" , ans);
    return 0;
}
