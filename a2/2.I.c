#include <stdio.h>
int main()
{
	int N, C, i, c = 0 ;
	scanf("%d %d", &N, &C);
	char dino[20];
	int d[36];
	for(i = 0; i < 36; i++)
		d[i] = 0 ;
	for(i = 0; i < N; i++)
	{
		scanf("%s", dino);
		if(((int)dino[0] >= 48) && ((int)dino[0] <= 57))
			d[(int)(dino[0])-22]++ ;
		else
			d[(int)(dino[0])-65]++ ;
	}
	for(i = 0; i < 36; i++)
		c += (((C-(d[i]-(d[i]/C)*C))*(((d[i]/C)*((d[i]/C)-1))/2))+(((d[i]-(d[i]/C)*C)*(((d[i]/C)*((d[i]/C)+1))/2))));
	printf("%d", c);
}
