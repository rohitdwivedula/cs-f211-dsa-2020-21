#include <stdio.h>
#include <stdlib.h>

struct node{
    unsigned long long int data;
    struct node* next;
    struct node* prev;
};

unsigned long long int hash(unsigned long long int x){
    x=x%65535;
    x*=(x+13);
    x=x%65535;
    return x;
}

int main()
{
    //printf("%u", hash(123*456));
    int n;
    scanf("%d", &n);
    struct node* head=NULL;
    struct node* tail=NULL;
    unsigned long long int temp;
    for(int i=0;i<n;i++){
        scanf("%llu", &temp);
        struct node* p= (struct node*)malloc(sizeof(struct node));
        p->data=temp;
        p->next=NULL;
        if(i==0){
            head=p;
            tail=p;
            p->prev=NULL;
        }
        else{
            p->prev=tail;
            tail->next=p;
            tail=p;
        }
    }
    struct node* point=NULL;
    while(head->next!=NULL){
        point=head;
        while(point!=NULL){
            if(point->next!=NULL){
                int product=(point->data)*(point->next->data);
                point->data=hash(product);
                point->next=point->next->next;
                if(point->next!=NULL)
                point->next->prev=point;
            }
            else{
                point->data=hash(point->data);
            }
            point=point->next;
        }
    }
    printf("%llu",head->data);
    return 0;
}
