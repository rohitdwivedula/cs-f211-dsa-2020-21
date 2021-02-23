#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n = 0 , k = 0;
char* val;

void print(char* text , int index){
    if(index == k){
        printf("%s\n" , text);
        return;
    }
    for(int i = 0;  i < n ; i++){
        char* temp = (char*)malloc(sizeof(char) * (k - index));
        strcpy(temp , text);
        strncat(temp , &val[i] , 1);
        print(temp , index + 1);
    }
    return;
}

int main()
{
    scanf("%d %d\n" , &n , &k);
    val = (char*)malloc(sizeof(char) * (n+1));
    for (int i = 0; i < n; i++)scanf("%c" , &val[i]);
    val[n] = '\0';
    char text[] = "";
    print(text , 0);
}
