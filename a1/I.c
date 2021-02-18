#include <stdio.h>
#include <stdlib.h>

typedef struct Nodetype
{
    int data;
    struct Nodetype *next;
} Node;

Node *head, *tail;

void add(int x)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = x;
    node -> next = NULL;
    if(!head)
        head = tail = node;
    else
    {
        tail -> next = node;
        tail = node;
    }
}

void traverse()
{
    Node* curr = head;
    while(curr)
    {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
}

void reverse(Node* curr)
{
    Node* head_copy = curr;
    Node* a = curr -> next, *b;
    while(a)
    {
        b = a -> next;
        a -> next = curr;
        curr = a;
        a = b;
    }
    head = tail;
    tail = head_copy;
    tail -> next = NULL;
}

int main()
{
    while(1)
    {
        int x;
        scanf("%d", &x);
        if(x == -1)
            break;
        add(x);
    }

    reverse(head);
    traverse();
    return 0;
}