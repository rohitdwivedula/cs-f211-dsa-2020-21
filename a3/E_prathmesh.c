#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll n, i = 0, pos = 0;
ll loop(ll iterations)
{
    ll count = 0;
    char action[10];
    i++;
    scanf("%s", &action);
    while (action[0] != 'E')
    {
        if (action[0] == 'F')
        {
            ll t;
            scanf("%lld", &t);
            count += t;
        }
        else
        {
            ll t;
            scanf("%lld", &t);
            count += loop(t);
        }
        i++;
        scanf("%s", &action);
    }
    return iterations * count;
}

int main()
{
    scanf("%lld", &n);
    while (i < n)
    {
        char action[10];
        scanf("%s", &action);
        if (action[0] == 'F')
        {
            ll t;
            scanf("%lld", &t);
            pos += t;
            i++;
        }
        else
        {
            ll t;
            scanf("%lld", &t);
            i++;
            pos += loop(t);
        }
    }
    printf("%lld", pos);
}