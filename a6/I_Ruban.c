#include <stdio.h>
void merge(int s, int arr[s][3], int l, int m, int r);
void sort(int s, int arr[s][3], int l, int r);
int N, i, j, k, am = 0, ay, p = 0, x, y ;
int main()
{
	scanf("%d", &N);
	int P[N][3];
	scanf("%d %d %d", &P[0][0], &P[0][1], &P[0][2]);
	ay = P[0][2];
	for(i = 1; i < N; i++)
	{
		scanf("%d %d %d", &P[i][0], &P[i][1], &P[i][2]);
		if(ay > P[i][2])
		{
			ay = P[i][2];	// finding out the hero
			am = i ;
		}
	}
	x = P[am][1];
	y = P[am][2];
	for(i = 0; i < N; i++)
	{
		if(P[i][1] > P[am][1])
			p++ ;
	}
	int pos[p][3], neg[N-1-p][3];	// storing the co-ordinates of villians towards the left and right of the hero respectively
	i = 0 ;
	j = 0 ;
	for(k = 0; k < N; k++)
	{
		if(k == am)
			continue ;
		if(P[k][1] > P[am][1])
		{
			pos[i][0] = P[k][0];
			pos[i][1] = P[k][1];
			pos[i++][2] = P[k][2];
		}
		else
		{
			neg[j][0] = P[k][0];
			neg[j][1] = P[k][1];
			neg[j++][2] = P[k][2];
		}
	}
	sort(p, pos, 0, p-1);
	sort(N-1-p, neg, 0, N-2-p);	// modified merge sort to sort according to "slope" of the line between each villian and the hero
	for(i = 0; i < p; i++)
		printf("%d ", pos[i][0]);
	for(i = 0; i < N-1-p; i++)
		printf("%d ", neg[i][0]);
}
void merge(int s, int arr[s][3], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	int a1[n1][3], a2[n2][3];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
		a1[i][2] = arr[l+i][2];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
		a2[i][2] = arr[m+1+i][2];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if((double)(a1[i][2]-y)/(a1[i][1]-x) < (double)(a2[j][2]-y)/(a2[j][1]-x))
		{
			arr[k][0] = a1[i][0];
			arr[k][1] = a1[i][1];
			arr[k++][2] = a1[i++][2];
		}
		else if((double)(a1[i][2]-y)/(a1[i][1]-x) > (double)(a2[j][2]-y)/(a2[j][1]-x))
		{
			arr[k][0] = a2[j][0];
			arr[k][1] = a2[j][1];
			arr[k++][2] = a2[j++][2];
		}
		else
		{
			if(a1[i][2] < a2[j][2])
			{
				arr[k][0] = a1[i][0];
				arr[k][1] = a1[i][1];
				arr[k++][2] = a1[i++][2];
			}
			else
			{
				arr[k][0] = a2[j][0];
				arr[k][1] = a2[j][1];
				arr[k++][2] = a2[j++][2];
			}
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k][1] = a1[i][1];
		arr[k++][2] = a1[i++][2];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k][1] = a2[j][1];
		arr[k++][2] = a2[j++][2];
	}
}
void sort(int s, int arr[s][3], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
