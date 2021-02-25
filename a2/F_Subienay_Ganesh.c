#include<stdio.h>

int twosum(int n, int k){

    if(n==0) return 1;
    if(k==0) return 1;

    int x = 1;
    for(int i = 0; i < k; i++) x *= 2;
    if(x<=n)
        return twosum(n-x,k)+twosum(n,k-1);
    else
        return twosum(n,k-1);

}

void main(){
    int n;
    scanf("%d",&n);

    int pow2 = 1,pcount = 0;
    while(pow2<n){
        pow2 *= 2;
        pcount++;
    }

    printf("%d",twosum(n,pcount));
}