#include <stdio.h>
#include <stdint.h>

#define MODULO 1000000007

int64_t factorial(int64_t input)
{
    if(input < 0)
    {
        return 0;
    }

    int64_t output = 1;
    for(int64_t i = 1; i <= input; i++)
    {
        output = output * i;
        output = output % MODULO;
    }

    return output;
}

int main(void)
{
    int64_t size;
    int64_t number;
    int64_t position;
    scanf("%li %li %li", &size, &number, &position);

    int64_t left = 0;
    int64_t right = size;
    int64_t middle;
    int64_t lesser_count = 0;
    int64_t greater_count = 0;

    while(left < right)
    {
        middle = (left + right) / 2;
        if(position > middle)
        {
            lesser_count = lesser_count + 1;
            left = middle + 1;
        }
        else if(position < middle)
        {
            greater_count = greater_count + 1;
            right = middle;
        }
        else if(position == middle)
        {
            break;
        }
    }

    lesser_count = ((number - 1) >= lesser_count) ? lesser_count : -1;
    greater_count = ((size - number) >= greater_count) ? greater_count : -1;
    uint64_t output = factorial(lesser_count) * factorial(greater_count);
    output = output % MODULO;
    output = output * factorial(size - lesser_count - greater_count - 1);
    output = output % MODULO;    
    printf("%lu", output, lesser_count, greater_count);
    fflush(stdout);
    return 0;
}