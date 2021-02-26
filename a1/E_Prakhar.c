#include<stdio.h>
#include<stdlib.h>

#define node struct node

node{
    int val;
    node* forward;
    node* backward;
};


int main(){
    char ch;
    node* head;
    node* tail;
    node* prev = (node*)malloc(sizeof(node));
    scanf("%c" , &ch);
    int i = 0;
    while(ch != '\n'){
        node* temp = (node*)malloc(sizeof(node));
        temp -> val = ch - '0';
        if(i){
            temp -> backward = prev;
            prev -> forward = temp;
            prev = temp;
        }else{
            temp -> backward = NULL;
            prev = temp;
            head = temp;
        }
        scanf("%c" , &ch);
        i++;
    }
    prev -> forward = NULL;
    tail = prev;
    int n,x;
    scanf("%d%*c", &n);
    node* temp;
    while (n--)
    {
        char command;
        scanf("%c", &command);
        switch (command)
        {
        case 'L':
            scanf("%c%*c", &command);
            if (command == 'S')
            {
                temp = head;
                while(temp -> forward != NULL){
                    temp -> val = (temp ->  forward) -> val;
                    temp = temp -> forward;
                }
                temp -> val = 0;
            }
            else
            {
                temp = head;
                int cpy = temp -> val;
                while(temp -> forward != NULL){
                    temp -> val = (temp ->  forward) -> val;
                    temp = temp -> forward;
                }
                temp -> val = cpy;
            }
            break;
        case 'R':
            scanf("%c%*c", &command);
            if (command == 'S')
            {
                temp = tail;
                while(temp -> backward != NULL){
                    temp -> val = (temp ->backward) -> val;
                    temp = temp -> backward;
                }
                temp -> val = 0;
            }
            else
            {
                temp = tail;
                int cpy = temp -> val;
                while(temp -> backward != NULL){
                    temp -> val = (temp ->backward) -> val;
                    temp = temp -> backward;
                }
                temp -> val = cpy;
            }
            break;
        case 'I':
                scanf("%*c%*c%*c");
                temp = tail;
                x = 1;
                while(temp != NULL){
                    int sum = (temp -> val) + x;
                    temp -> val = sum % 2;
                    x = sum / 2;
                    temp  = temp -> backward;
                }
            break;
        case 'D':
                scanf("%*c%*c%*c");
                temp = tail;
                x = 0;
                while(temp != NULL){
                    int sum = (temp -> val) + x + 1;
                    temp -> val = sum % 2;
                    x = sum / 2;
                    temp = temp -> backward;
                }
            break;
        }
    }
    while(head != NULL){
        printf("%d" , head -> val);
        head = head -> forward;
    }
    return 0;
}
