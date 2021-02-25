#include <stdio.h>
#include <stdlib.h>

void find(int textLength, int index, int level, int occurenceCount)
{
    char ch;
    scanf("%c", &ch);
    if (ch == 'b' && level == 0)level = 1;
    else if (ch == 'a' && level == 1)level = 2;
    else if (ch == 'a' && level == 2)level = 3;
    else if (ch == 'b' && level == 3)
    {
        level = 1;
        occurenceCount++;
        if (occurenceCount == 1)
        {
            printf("YES %d", index - 3);
        }
        else
        {
            printf(" %d", index - 3);
        }
    }
    else  level = 0;
    if ((index + 1) > textLength)
    {
        if (occurenceCount == 0)printf("NO");
        return;
    }
    find(textLength, index + 1, level, occurenceCount);
}

int main()
{
    int n;
    scanf("%d", &n);
    find(n, 0, 0, 0);
    return 0;
}
