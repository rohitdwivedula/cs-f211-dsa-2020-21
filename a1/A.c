/**
 * This is an original solution of 1A. 
 * We are not allowed to use most common methods of normally solving
 * this problem, such as loops, arrays, pointers and strings. However,
 * we can still use recursion.
 * 
 * Therefore, we can create a function that has a recursive loop in it.
 * In the loop, we progressvively check for a b or a, based on a state flow,
 * such as b->a->a->b. If this condition is fulfilled in the current run of the
 * function, add 1 to the total. Otherwise, increment a counter for the state table
 * and run the function again with the new counter value.
 * 
 * Assumed Total complexity = O(n)
 * 
 **/


#include<stdio.h>
 
 //recursive function call
void checkbaab(int flag,int pos,int n,int f2);
 
void main()
{
    int n;
 
    scanf("%d",&n);
    
    int flag = 0, pos = 0;
 
    checkbaab(flag,pos,n,0);
 
}
 
void checkbaab(int flag,int pos,int n, int f2){
    //If the string value has been exceeded
    if(pos>n){
        if(!f2) printf("NO");
        return;
    }
    else{
        char ch;
        scanf("%c",&ch);
        //State checking
        if((flag==0 && ch=='b') || (flag==1 && ch=='a') || (flag==2 && ch=='a'))
            flag++;
        //Final state
        else if(flag==3 && ch=='b'){
            flag=1;
            if(!f2) printf("YES ");
            printf("%d ",(pos-3));
            f2=1;
        }
        else if(ch=='b') flag=1; else flag=0;
        pos++;
        //recursion step, flag is the new counter value
        checkbaab(flag,pos,n,f2);
    }
}