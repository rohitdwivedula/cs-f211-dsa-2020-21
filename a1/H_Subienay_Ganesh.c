#include<stdio.h>

/**
 * 
 * Rotating an array uses the same logic as in 1E. This is a
 * simple brute force solution where you store a potential max or min cost
 * and compare it with the current max or min.
 * Total Complexity = O(n^2)
 * 
 * **/

void main(){

    int n;
    scanf("%d",&n);

    int a[500];

    long int es = 0, oc = 0;

    long long int maxc = 0, minc = 10000000000;

    for(int j = 0; j < n; j++){
            scanf(" %d",&a[j]);
    }

    for(int i = 0; i <= n; i++){

        es = oc = 0;

        for(int j = 0; j < n; j++){
            if(j%2==0)
                es += a[j]*a[j];
            else
                oc += a[j]*a[j]*a[j];
        }

        int tc = es > oc ? es-oc : oc-es;

        if(tc>maxc){
            maxc = tc;
            printf("max %d\n",maxc);
        }
        else if(tc<minc){
            minc = tc;
            printf("min %d\n",minc);
        }

        //Rotate

        int temp = a[0];

        for(int j = 1; j < n; j++)
            a[j-1] = a[j];

        a[n-1] = temp;
    }

    printf("%d",(maxc-minc));

}