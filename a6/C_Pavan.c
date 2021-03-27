#include <stdio.h>
#include <stdlib.h>

int checkFit(int **arr, int n, int temp)
{
	int a = 0;
	for(int i=0; i<n; i++)
	{
		a += temp/(*arr)[i];
	}
	return a;
}

int binarySearch(int** arr, int n, int k, int high)
{
	int low=0;

	while(low<high)
	{
		int mid = (high+low)>>1;

		int item = checkFit(arr, n, mid);

		if (item<k)
		{
			low=mid+1;
		}
		else
		{
			high=mid;
		}
	}

	return high;

}

int minVal(int **arr, int n, int k)
{
	int max = 0;

	for(int i=0; i<n; i++)
	{
		if((*arr)[i]>max)
		{
			max = (*arr)[i];
		}
	}
	return binarySearch(arr, n, k, max*k);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int *arr = (int*) malloc(n*(sizeof(int)));
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int result = minVal(&arr, n, k);

	printf("%d", result);
	return 0;
}