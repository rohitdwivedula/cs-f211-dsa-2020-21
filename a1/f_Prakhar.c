#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool* isPrime;
int freq[10];

void digfreq(long long n){
    while(n){
        freq[n%10]++;
        n /= 10;
    }
}

void precompute(int n){
    for(int i = 2 ; i*i <= n ; i++){
        if(isPrime[i]){
            for(int j = i * i ; j <= n ; j += i)
                isPrime[j] = false;
        }
    }
}

void computeFreq(long long L , long long  R , int n){
    bool* prime = (bool*)malloc(sizeof(bool) * (R - L + 1));
    for(int i = 0 ; i < (R - L + 1) ; i++)prime[i] = true;
    for(int i = 0 ; i < n ; i++){
        if(isPrime[i]){
            long long lower = L;
            if((lower%i) != 0)lower += i - lower%i;
            if(lower == i)lower += i;
            while(lower <= R){
                prime[lower - L] = false;
                lower += i;
            }
        }
    }
    if(L == 1)prime[0] = false;
    for(int i = 0 ; i < (R - L + 1) ; i++){
        if(prime[i]){
            digfreq(i + L);
        }
    }
    int ans = freq[0];
    int dig = 0;
    for(int i = 0 ; i < 10 ; i++){
        if(freq[i] > ans){
            ans= freq[i];
            dig = i;
        }
    }
    printf("%d %d" , dig , ans);
}

int main(){
    long long  a,b;
    scanf("%lld%lld" , &a , &b);
    if(a == 0)a = 1;
    int lim = sqrt(b) + 5;
    isPrime = (bool*)malloc(sizeof(bool) * lim);
    for(int i = 0 ; i < lim ; i++)isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for(int i = 0 ; i < 10 ; i++)freq[i] = 0;
    precompute(sqrt(b) + 1);
    computeFreq(a , b , sqrt(b) + 1);
    return 0;
}
