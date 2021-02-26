#include <stdio.h>

int f(int n)
{
    return n * (n - 1) / 2;
}

int min(int a , int b)
{
    if(a < b)return a;
    return b;
}

int main()
{
    int n,c;
    scanf("%d %d\n" , &n , &c);
    int freq[26+10];
    for(int i = 0 ; i < 26+10 ; i++)
        freq[i] = 0;
    for(int i = 0 ; i < n ; i++)
    {
        char code[20];
        scanf("%s" , code);
        if(code[0] <= '9')
            freq[code[0] - '0' + 26]++;
        else freq[code[0] - 'A']++;
    }
    int ans = 0;
    for(int i = 0 ; i <26+10 ; i++)
    {   
        ans += (freq[i]%c) * f((freq[i]/c + 1));
        ans += (min(c , freq[i]) - freq[i]%c) * f(freq[i]/c);
    }
    printf("%d" , ans);

}
