#include <stdio.h>
#include <stdlib.h>
#define N 2000

typedef struct Nodetype
{
    char data;
    struct Nodetype *next, *prev;
} Node;

Node *head, *tail;

void append_node(char ch)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node -> next = node -> prev = NULL;
    node -> data = ch;

    if(!head)
        head = tail = node;
    else
    {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
}

int is_palindrome()
{
    Node *first = head, *last = tail;
    while(first != last)
    {
        if(first -> data != last -> data)
            return 0;
        first = first -> next;
        last = last -> prev;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d%*c", &n);
    for(int i = 0; i < n; i++)
    {
        char ch;
        scanf("%c", &ch);
        append_node(ch);
    }

    printf("%s", (is_palindrome() ? "PALINDROME" : "NOT A PALINDROME"));
    return 0;
}