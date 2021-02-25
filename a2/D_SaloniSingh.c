#include<stdio.h>
#define ll long long
#define mod 1000000007
int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    int P[n],multi[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&P[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%lld",&multi[i]);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if((i+j)<n)
            P[i+j]=(P[i+j]%mod * multi[i]%mod)%mod;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%lld ",P[i]);
    }
    
    
    
    

    return 0;
}