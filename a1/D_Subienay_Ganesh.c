#include<stdio.h>

/**
 * This problem uses the concept of bitmasks.
 * We can take a number such as 8 and represent it as a binary number
 * like 100. This makes it very easy to go through permutations of items 
 * using the << and >> operator. For example, to permute between
 * 3 items, we make a loop from 0 to 1<<3 == 8.
 * Total Complexity = O(n*2^n)
 * **/

void main(){

    int m,n;

    scanf("%d",&m);
    scanf("%d",&n);

    int p[25];

    for(int i = 0; i < n; i++)
        scanf(" %d",&p[i]);

    int sum,count;
    int max = 0;
    
    //bitmask looping
    for(int mask = 0; mask<(1<<n); mask++){
        sum = 0;
        count = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)){
                sum += p[i];
                count++;
            }
        }
        if(sum<=m && count>max)
            max = count;
    }

    printf("%d",max);

}