#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parity_checker(int a, int b);

int main(){
    int N;
    scanf("%d",&N);
    int d[N];
    int q=0;
    int query[N];
    int j=0;
    int c=0;
    int max=0;
    for(int i=0;i<N-1;i++){
        char s[6];
        int t=0;
        scanf("%s %d",s,&t);
        if(s[0]=='a'){
            d[j++]=t;
        }
        else if(s[0]=='d'){
            for(int k=0;k<j;k++){
                if(d[k]==t){
                    d[k]=-1;
                    break;
                }
            }
        } else {
            int h=0;
            for(int k=0;k<j;k++){
                if(d[k]!=-1){
                    h+=parity_checker(d[k],t);
                }
            }
            query[q++]=h;
        }
    }
    for(int i=0;i<q;i++)printf("%d\n",query[i]);
}

int parity_checker(int a, int b){
    for(int i=1;i<=9;i++){
        if((a%10 + b%10) % 2){
            return 0;
        }
        a/=10;
        b/=10;
    }
    return 1;
}