#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int n;

//Bucket Structure containing the (x,y) values in seperate 1D arrays and their respective count.
struct Bucket
{
	double *Bx;
	double *By;
	int cx;
	int cy;
	int boole;
};

//Intializaing a bucket
struct Bucket* init_bucket()
{
	struct Bucket* new = malloc(sizeof(struct Bucket));
	new->Bx = (double*)malloc(n*sizeof(double));
	new->By = (double*)malloc(n*sizeof(double));
	new->cx=0;
	new->cy=0;
	new->boole=1;
	return new;
}

//Adding en element to a bucket.
void add_element(struct Bucket** bucket, int x, double val)
{
	int a = (int)(val);
	if(bucket[a]==NULL)
	{
		bucket[a] = init_bucket();
	}
	else if(bucket[a]->boole!=1)
	{
		bucket[a] = init_bucket();
	}

	int i;
	if(x==1)
	{
		i = bucket[a]->cx;
		(bucket[a]->Bx)[i] = val;
		bucket[a]->cx++;
	}
	else
	{
		i = bucket[a]->cy;
		(bucket[a]->By)[i] = val;
		bucket[a]->cy++;
	}
	//printf("Counts of Bucket with range (%d, %d) : \n\tcx and cy : %d %d\n", a, a+1, bucket[a]->cx, bucket[a]->cy);
}

//Looping through an array of all buckets (that is through all the ranges) and setting the count for the bucket in which 'a' is present.
//x value shows if we are working with 'x' values (x=1) or 'y' vlaues (x=0)
int bucket_count(struct Bucket** bucket, int n1, double a, int x)
{
	double *arr;
	int size;

	for(int j=0; j<n1; j++)
	{
		if(bucket[j]!=NULL && bucket[j]->boole==1)
		{
			arr = x==1? bucket[j]->Bx : bucket[j]->By;
			size = x==1? bucket[j]->cx : bucket[j]->cy;
			size = size>n? n:size;

			for(int i=0; i<size; i++)
			{
				if(arr[i]==a)
				{
					return x==1? bucket[j]->cx : bucket[j]->cy;
				}
			}
		}
	}
}

//compare function for quicksort
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

//Sorting the array of normality scores and printing the indexes of 'k' element with the least values.
void print(int* arr, int k)
{
	int n1[MAX] = {0};
	for(int i=0; i<n; i++)
	{
		n1[i] = arr[i];
	}
	int l = n;
	qsort(arr, l, sizeof(int), cmpfunc);
	int count =0;

	for(int i=0; i<k; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i]==n1[j])
			{
				if(i!=k-1)
				{
					printf("%d ", j);
					count++;
				}
				else
				{
					printf("%d", j);
					count++;
				}
				if(count>=k)
				{
					return;
				}
			}
		}
	}
}


int main()
{
	int c, d, k;
	scanf("%d %d %d %d", &n, &c, &d, &k);

	//Using a bucket Data Sturcture to store the values and counts of each range.	
	struct Bucket** buc = c>=d? malloc(c*sizeof(struct Bucket)) : malloc(d*sizeof(struct Bucket));

	//Taking input of each points and adding them to their respective buckets.
	double* x = (double*)malloc(n*sizeof(double));
	double* y = (double*)malloc(n*sizeof(double));
	for(int i=0; i<n; i++)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		add_element(buc, 1, x[i]);
		add_element(buc, 0, y[i]);
	}
	
	//Calculating the normality scores.
	int size = c>=d? c:d;
	int* n1= (int*)malloc(n*sizeof(int));
	for(int i=0;  i<n; i++)
	{
		n1[i] = bucket_count(buc, size, x[i], 1) * bucket_count(buc, size, y[i], 0);
		//printf("Normality Score of (%lf, %lf) : %d\n", x[i], y[i], n1[i]);
	}

	//Sorting the array of normality scores and printing the indexes of 'k' element with the least values.
	print(n1, k);
	return 0;
}

//Given smaple test case in the lab sheet.
/*
4 10 10 2
3.1 3.2
3.3 7.7
9.1 3.2
0.1 2.9
*/