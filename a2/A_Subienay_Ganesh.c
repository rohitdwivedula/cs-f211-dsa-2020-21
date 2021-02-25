#include<stdio.h>
#include<math.h>

int ghot(int);

void main(){

    int n;
    scanf("%d",&n);

    printf("%d",ghot(n));

}

int ghot(int x){

    int div[] = {0,0};
    int a = 0;

    for(int i = x-1; i > 1; i--){
        if(x%i==0){
            div[a] = i;
            a++;
        }
    }

    if(div[1]==0)
        return x;
    else
        return ghot(div[0])+ghot(div[1]);

}