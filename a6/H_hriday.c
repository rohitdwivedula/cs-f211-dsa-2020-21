/**
 * Hriday G
 * 2019A7PS1212H
 * 26.03.2021 13:21:08
 * Implicit Treap with lazy propagation
 * Time complexity: O(n + Qlogn)
    where Q denotes number of bracket pairs,
    and n denotes number of non bracket characters.
 * Note: undefined behaviour if input has ...[.(..]..)..
    as order is not defined in such a case.
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 200005

typedef struct Node {
    int priority, sz;
    int val, lzy, rev;
    long long sum;
    struct Node *l, *r;
} Node;

typedef Node* Treap;

Node __T_nil = { .priority = -1, .sz = 0, .val = 0, .sum = 0, .lzy = 0, .rev = 0, .l = NULL, .r = NULL };
Treap T_nil = &__T_nil;

Treap newTreap(int val) {
    Treap t = malloc(sizeof *t);
    t->priority = rand() << 15 ^ rand();
    t->val = t->sum = val; t->sz = 1;
    t->lzy = t->rev = 0;
    t->l = t->r = T_nil;
    return t;
}

void push(Treap t) {
    if(t == T_nil) return;
    if(t->lzy) {
        t->l->lzy += t->lzy;
        t->r->lzy += t->lzy;
        t->val += t->lzy;
        t->lzy = 0;
    }
    if(t->rev) {
        Treap tmp = t->l;
        t->l = t->r; t->r = tmp;
        t->l->rev ^= 1;
        t->r->rev ^= 1;
        t->rev = 0;
    }
}

void pull(Treap t) {
    if(t == T_nil) return;
    push(t->l); push(t->r);
    t->sz = t->l->sz + 1 + t->r->sz;
    t->sum = t->l->sum + t->val + t->r->sum;
}

void split(Treap t, Treap *l, Treap *r, int pos, int add ) {
    if(t == T_nil) {
        *l = *r = T_nil;
        return;
    }
    push(t);
    if(pos <= add + t->l->sz)
        split(t->l, l, &t->l, pos, add), *r = t;
    else
        split(t->r, &t->r, r, pos, add + t->l->sz + 1), *l = t;
    pull(t);
}

void merge(Treap *t, Treap l, Treap r) {
    push(l); push(r);
    if(l == T_nil)
        *t = r;
    else if(r == T_nil)
        *t = l;
    else if(l->priority > r->priority)
        merge(&l->r, l->r, r), *t = l;
    else
        merge(&r->l, l, r->l), *t = r;
    pull(*t);
}

void heapify(Treap t) {
    if(t == T_nil) return;
    Treap mx = t;
    if(t->l->priority > mx->priority)
        mx = t->l;
    if(t->r->priority > mx->priority)
        mx = t->r;
    if(mx != t) {
        int tmp = t->priority;
        t->priority = mx->priority;
        mx->priority = tmp;
        heapify(mx);
    }
}

Treap build(const char *beg, const char *end) {
    if(end - beg < 2)
        return end == beg? T_nil : newTreap(*beg - 'a');
    const char *mid = beg + (end - beg >> 1);
    Treap t = newTreap(*mid - 'a');
    t->l = build(beg, mid);
    t->r = build(++mid, end);
    heapify(t); pull(t);
    return t;
}

// [l, r)
void update(Treap t, int l, int r, void (*f)(Treap)) {
    Treap tl, _, tr;
    split(t, &tl, &_, l, 0);
    split(_, &t, &tr, r-l, 0);
    f(t);
    merge(&_, tl, t);
    merge(&t, _, tr);
}

void increment(Treap t) { ++t->lzy; }
void reverse(Treap t) { t->rev ^= 1; }

void print(Treap t) {
    if(t == T_nil) return;
    push(t); print(t->l);
    printf("%c", t->val % 26 + 'a');
    print(t->r); pull(t);
}

struct Query {
    int type, l, r;
} queries[N];

int main() {
    srand(time(NULL));
    static char input[N], s[N];
    scanf("%s", input);
    int _sz = strlen(input), q = 0, n = 0, top = -1;

    static int stack[N];
    for(int i = 0; i < _sz; i++) {
        if(input[i] == ')' || input[i] == ']')
            queries[q++] = (struct Query){ input[i] == ')', stack[top--], n };
        else if(input[i] == '(' || input[i] == '[')
            stack[++top] = n;
        else s[n++] = input[i];
    }
    
    Treap t = build(s, s+n);

    for(int i = 0; i < q; i++)
        update(t, queries[i].l, queries[i].r,
            queries[i].type? reverse : increment);

    print(t);
}