#include<stdio.h>
 
void checkbaab(int flag,int pos,int n,int f2);
 
void main()
{
    int n;
 
    scanf("%d",&n);
    
    int flag = 0, pos = 0;
 
    checkbaab(flag,pos,n,0);
 
}
 
void checkbaab(int flag,int pos,int n, int f2){
    if(pos>n){
        if(!f2) printf("NO");
        return;
    }
    else{
        char ch;
        scanf("%c",&ch);
        if((flag==0 && ch=='b') || (flag==1 && ch=='a') || (flag==2 && ch=='a'))
            flag++;
        else if(flag==3 && ch=='b'){
            flag=1;
            if(!f2) printf("YES ");
            printf("%d ",(pos-3));
            f2=1;
        }
        else if(ch=='b') flag=1; else flag=0;
        pos++;
        checkbaab(flag,pos,n,f2);
    }
}