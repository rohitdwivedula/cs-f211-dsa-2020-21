#include <stdio.h>
void merge(int s, float arr[s][4], int l, int m, int r);
void sort(int s, float arr[s][4], int l, int r);
int main()
{
	int N, C, D, k, i ;
	scanf("%d %d %d %d", &N, &C, &D, &k);
	float P[N][4];
	int X[C], Y[D];
	for(i = 0; i < C; i++)
		X[i] = 0 ;
	for(i = 0; i < D; i++)
		Y[i] = 0 ;
	for(i = 0; i < N; i++)
	{
		P[i][0] = (float)i ;
		scanf("%f %f", &P[i][1], &P[i][2]);
		X[(int)P[i][1]]++ ;
		Y[(int)P[i][2]]++ ;
	}
	printf("\n");
	for(i = 0; i < N; i++)
		P[i][3] = (float)X[(int)P[i][1]]*(float)Y[(int)P[i][2]];
	sort(N, P, 0, N-1);
	for(i = 0; i < N; i++)
		printf("%f %f %f %f\n", P[i][0], P[i][1], P[i][2], P[i][3]);
	printf("\n");
	for(i = 0; i < k; i++)
		printf("%d ", (int)P[i][0]);
}
void merge(int s, float arr[s][4], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m, i, j, k ;
	float a1[n1][3], a2[n2][3];
	for(i = 0; i < n1; i++)
	{
		a1[i][0] = arr[l+i][0];
		a1[i][1] = arr[l+i][1];
		a1[i][2] = arr[l+i][2];
		a1[i][3] = arr[l+i][3];
	}
	for(i = 0; i < n2; i++)
	{
		a2[i][0] = arr[m+1+i][0];
		a2[i][1] = arr[m+1+i][1];
		a2[i][2] = arr[m+1+i][2];
		a2[i][3] = arr[m+1+i][3];
	}
	i = 0 ;
	j = 0 ;
	k = l ;
	while((i < n1) && (j < n2))
	{
		if(a1[i][3] < a2[j][3])
		{
			arr[k][0] = a1[i][0];
			arr[k][1] = a1[i][1];
			arr[k][2] = a1[i][2];
			arr[k++][3] = a1[i++][3];
		}
		else if(a1[i][3] > a2[j][3])
		{
			arr[k][0] = a2[j][0];
			arr[k][1] = a2[j][1];
			arr[k][2] = a2[j][2];
			arr[k++][3] = a2[j++][3];
		}
		else
		{
			if(a1[i][0] < a2[j][0])
			{
				arr[k][0] = a1[i][0];
				arr[k][1] = a1[i][1];
				arr[k][2] = a1[i][2];
				arr[k++][3] = a1[i++][3];
			}
			else
			{
				arr[k][0] = a2[j][0];
				arr[k][1] = a2[j][1];
				arr[k][2] = a2[j][2];
				arr[k++][3] = a2[j++][3];
			}
		}
	}
	while(i < n1)
	{
		arr[k][0] = a1[i][0];
		arr[k][1] = a1[i][1];
		arr[k][2] = a1[i][2];
		arr[k++][3] = a1[i++][3];
	}
	while(j < n2)
	{
		arr[k][0] = a2[j][0];
		arr[k][1] = a2[j][1];
		arr[k][2] = a2[j][2];
		arr[k++][3] = a2[j++][3];
	}
}
void sort(int s, float arr[s][4], int l, int r)
{
	if(l < r)
	{
		sort((l+r)/2-l+1, arr, l, (l+r)/2);
		sort(r-((l+r)/2), arr, (l+r)/2 + 1, r);
		merge(s, arr, l, (l+r)/2, r);
	}
}
