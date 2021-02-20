#include<stdio.h>

void main(){

    int m,n;

    scanf("%d",&m);
    scanf("%d",&n);

    int p[25];

    for(int i = 0; i < n; i++)
        scanf(" %d",&p[i]);

    int sum,count;
    int max = 0;

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