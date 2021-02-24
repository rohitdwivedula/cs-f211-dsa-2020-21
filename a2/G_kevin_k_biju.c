#include <stdio.h>
#include <stdlib.h>

int sort_function(const void* a, const void* b)
{
    return (*(int*)a) > (*(int*)b);
}

int main(void)
{
    int count;
    int box_size;
    scanf("%d", &count);
    int array[count];
    for(int i = 0; i < count; i++)
    {
        scanf("%d ", &array[i]);
    }
    scanf("%d", &box_size);
    qsort(array, count, sizeof(int), sort_function);    

    int lindex = 0;
    int uindex = count - 1;
    int box_count = 0;
    while(uindex > lindex)
    {
        if(array[lindex] + array[uindex] <= box_size)
        {
            lindex = lindex + 1;
            uindex = uindex - 1;
            box_count = box_count + 1;
        }
        else
        {
            uindex = uindex - 1;
            box_count = box_count + 1;
        }
    }
    printf("%i", box_count);
}