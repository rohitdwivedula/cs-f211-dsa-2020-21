#include <stdio.h>

#define N (int)1e6

long long n, sum, a[N], cur = 1, level = 1;

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		sum += (a[i] * level);
		if (i == cur - 1)
			cur += (1 << level), level++;
	}

	printf("%lld", sum);

	return 0;
}