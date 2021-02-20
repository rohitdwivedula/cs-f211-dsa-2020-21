#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct reg{
    char val;
    struct reg *prev;
    struct reg *next;
};

struct reg *head = NULL;
struct reg *tail = NULL;

void lr(void);
void rr(void);
void ls(void);
void rs(void);
void inc(struct reg*);
void dec(struct reg*);

void main(){

    char b[1000];
    int t,n;

    int i = 0;
    while((b[i++]=getchar())!='\n' && i<1000);
    b[i-1] = '\0';
    n = i-1;

    scanf("%d",&t);

    for(int i = 0; i < n; i++){
        struct reg *temp = (struct reg*) malloc(sizeof(struct reg));
        temp->val = b[i];
        temp->prev = tail;
        temp->next = NULL;
        if(tail!=NULL) tail->next = temp;
        if(head==NULL) head = temp;
        tail = temp;
    }

    char cmd[5];

    for(int i = 0; i <= t; i++){
        int j = 0;
        while((cmd[j++]=getchar())!='\n' && j < 5);
        cmd[j-1]='\0';

        if(strcmp(cmd,"LR")==0)
            lr();
        else if(strcmp(cmd,"RR")==0)
            rr();
        else if(strcmp(cmd,"LS")==0)
            ls();
        else if(strcmp(cmd,"RS")==0)
            rs();
        else if(strcmp(cmd,"INC")==0)
            inc(tail);
        else if(strcmp(cmd,"DEC")==0)
            dec(tail);
    }

    struct reg *temp = head;
    while(temp!=NULL){
        printf("%c",temp->val);
        temp = temp->next;
    }

}

void lr(){
    char tval = head->val;
    struct reg *temp = head;
    while(temp->next!=NULL){
        temp->val = (temp->next)->val;
        temp = temp->next;
    }
    temp->val = tval;
}

void rr(){
    char tval = tail->val;
    struct reg *temp = tail;
    while(temp->prev!=NULL){
        temp->val = (temp->prev)->val;
        temp = temp->prev;
    }
    temp->val = tval;
}

void ls(){
    lr();
    tail->val = '0';
}

void rs(){
    rr();
    head->val = '0';
}

void inc(struct reg *pt){
    if(pt->val=='0')
        pt->val = '1';
    else{
        pt->val = '0';
        if(pt->prev!=NULL) inc(pt->prev);
    }
}

void dec(struct reg *pt){
    if(pt->val=='1')
        pt->val = '0';
    else{
        pt->val = '1';
        if(pt->prev!=NULL) dec(pt->prev);
    }

}