#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parity(char a[], char b[]){
    int na=strlen(a);
    int nb=strlen(b);
    int i=na-1, j=nb-1;
    while(i>=0 || j>=0){
        int ai, bj;
        if(i<0) ai=0;
        else
        ai=(a[i]-'0')%2;
        if(j<0) bj=0;
        else
        bj=(b[j]-'0')%2;
        if(ai!=bj) return 0;
        i--;
        j--;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int top=-1;
    char buffer[n][11];
    char s1[10], s2[11];
    for(int i=0;i<n;i++){
        scanf("%s %s", s1,s2);
        if(s1[0]=='a'){
            top++;
            strcpy(buffer[top],s2);
        }
        else if(s1[0]=='d')
            for(int j=0;j<=top;j++){
                if(strcmp(buffer[j],s2)==0){
                    strcpy(buffer[j],"null");
                    break;
                }
            }
        else{
            int count=0;
            for(int j=0;j<=top;j++)
                count+=parity(buffer[j],s2);
            printf("%d\n", count);
        }
    }
    return 0;
}
