#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data ;
	struct node *next ;
};
void findleaf(int s, int arr[], int x, struct node **v);
int hamming(int x, int y);
void print(struct node *vertex);
void push(struct node **vertex, int x);
int main()
{
	int N, a, b, i, x = -1, y = -1, mhd ;
	scanf("%d %d %d", &N, &a, &b);
	int A[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if(A[i] == a)
			x = i ;
		if(A[i] == b)
			y = i ;
	}
	if((x == -1) || (y == -1))
	{
		printf("-1");
		exit(0);
	}
	struct node *A1 = NULL, *A2 = NULL, *t1, *t2 ;
	findleaf(N, A, x, &A1);
	findleaf(N, A, y, &A2);
	mhd = hamming(A1->data, A2->data);
	t1 = A1 ;
	while(t1 != NULL)
	{
		t2 = A2 ;
		while(t2 != NULL)
		{
			if((hamming(t1->data, t2->data) < mhd) || (t1->data != t2->data))
				mhd = hamming(t1->data, t2->data);
			t2 = t2->next ;
		}
		t1 = t1->next ;
	}
	printf("%d", mhd);
}
void findleaf(int s, int arr[], int x, struct node **v)
{
	if((arr[2*x+1] == -1) && (arr[2*x+2] == -1))
		push(v, arr[x]);
	else if(2*x+1 >= s)
		push(v, arr[x]);
	else
	{
		if(arr[2*x+1] != -1)
			findleaf(s, arr, 2*x+1, v);
		if(arr[2*x+2] != -1)
			findleaf(s, arr, 2*x+2, v);
	}
}
int hamming(int x, int y)
{
	int h = 0 ;
	x ^= y ;
	while(x > 0)
	{
		h += (x&1);
		x >>= 1 ;
	}
	return h ;
}
void print(struct node *vertex)
{
	struct node *ptr = vertex ;
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void push(struct node **vertex, int x)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = x ;
	if(vertex == NULL)
		ptr->next = NULL ;
	else
		ptr->next = (*vertex);
	(*vertex) = ptr ;
}
