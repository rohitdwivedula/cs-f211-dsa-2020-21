#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

int main()
{
    int n, m, temp;
    scanf("%d %d",&n,&m);
    int a[m];
    struct node* head=NULL;
    struct node* tail=NULL;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        struct node* p=(struct node*)malloc(sizeof(struct node));
        p->data=temp;
        if(tail!=NULL)tail->next=p;
        p->prev=tail;
        tail=p;
        p->next=NULL;
        if(i==0) head=p;
    }
    for(int i=0;i<m;i++){
        scanf("%d", &a[i]);
    }
    struct node* cur=head;
    struct node* swap, *h, *t;
    for(int i=0;i<m;i++){
        for(int j=0;j<a[i];j++){
            if(j==0) h=cur;
            if(j==a[i]-1) t=cur;
            //changing the links
            swap=cur->prev;
            cur->prev=cur->next;
            cur->next=swap;
            //changing value of data
            cur->data*=a[i];
            //then changing the value of cur
            cur=cur->prev;
        }
        swap=h->next;
        h->next=t->prev;
        t->prev=swap;
        if(h->next!=NULL) h->next->prev=h;
        if(t->prev!=NULL) t->prev->next=t;
        if(i==0) head=t;
    }
    cur=head;
    //printf("%d\n",cur->data);
    while(cur!=NULL){
        printf("%d",cur->data);
        if(cur->next!=NULL) printf(" ");
        cur=cur->next;
    }
    return 0;
}
