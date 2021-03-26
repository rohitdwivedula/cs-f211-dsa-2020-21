#include <stdio.h>
int main()
{
	int N ;
	scanf("%d", &N);
	if(N == 0)
		printf("0");
	else
	{
		if(N < 0)
		{
			printf("-");
			N *= -1 ;
		}
		int i ;
		for(i = 1; i*i*i <= N; i++);
		printf("%d", --i);
	}
}
