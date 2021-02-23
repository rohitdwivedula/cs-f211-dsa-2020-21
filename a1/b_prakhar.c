#include<stdio.h>
#include<stdlib.h>

#define node struct node

node{
    char character;
    node* forward;
    node* backward;
};


int main(){
    int n;
    scanf("%d%*c" , &n);
    char ch;
    node* head;
    node* tail;
    node* prev = (node*)malloc(sizeof(node));
    for(int i = 0 ; i < n ; i++){
        scanf("%c" , &ch);
        node* temp = (node*)malloc(sizeof(node));
        temp -> character = ch;
        if(i){
            temp -> backward = prev;
            prev -> forward = temp;
            prev = temp;
        }else{
            temp -> backward = NULL;
            prev = temp;
            head = temp;
        }
    }
    prev -> forward = NULL;
    tail = prev;
    int l = 0 , r = n-1;
    while(l <= r){
        if(head->character != tail->character) return printf("NOT A PALINDROME");
        head = head -> forward , l++;
        tail = tail -> backward  , r--;
    }
    printf("PALINDROME");
    return 0;
}
