#include <stdio.h>
#include <stdlib.h>
int sort(const void * x, const void * y);
int main()
{
	int N, i, s = 0, r = 0 ;
	scanf("%d", &N);
	int h[N], t[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &h[i]);
		t[i] = h[i];
	}
	qsort(t, N, sizeof(int), sort);
	for(i = 0; i < N; i++)
	{
		r += (t[i]-h[i]);
		if(r == 0)
			s++ ;
	}
	printf("%d", s);
}
int sort(const void * x, const void * y)
{
	return (*(int*)x - *(int*)y);
}
