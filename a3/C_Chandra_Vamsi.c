#include <stdio.h>
#include <stdlib.h>

#define N (int)1e5 + 5

long long n, m, x[N];

int binary_search();
int checkValid(int num);

int cmp (const void *a, const void *b)
{
	if (*(long long*)a > *(long long*)b) return 1;
	if (*(long long*)a < *(long long*)b) return -1;
	return 0;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%lld", &x[i]);

	qsort(x, m, sizeof(long long), cmp);

	printf("%d", binary_search());

	return 0;
}

int binary_search()
{
	int l = 1, r = x[m - 1] - x[0];
	while (l < r)
	{
		int mid = (l + r)/2;
		if (checkValid(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (checkValid(l))
		return l;
	return l - 1;
}

int checkValid(int num)
{
	int cnt = 1, cur = 0, pos = 1;
	while (cur < m && pos < m)
	{
		if (x[pos] - x[cur] >= num)
			cur = pos, cnt++;
		pos++;
	}
	if (cnt >= n)
		return 1;
	return 0;
}
