#include <stdio.h>
#include <stdlib.h>
#define N 50000

int seats[N+1]; // 1 is occupied, 0 is vacant;
int max_occupied = 1;

int find_vacant_spot()
{
    for(int i = 1; i <= N; i++)
        if(!seats[i])
            return i;
    return -1;
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        char ch;
        int n, j;
        scanf("%*c%c%d", &ch, &n);
        if(ch == 'E')
        {
            while(n--)
            {
                j = find_vacant_spot();
                if(j > max_occupied)
                    max_occupied = j;
                seats[j] = 1;
            }
        }
        else if(ch == 'L')
        {
            while(n--)
            {
                scanf("%d", &j);
                seats[j] = 0;
            }
        }
    }

    printf("%d", max_occupied);
    return 0;
}