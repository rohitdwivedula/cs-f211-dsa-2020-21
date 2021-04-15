/*
Problem 7I

*/

#include <stdio.h>

#define N 10001
#define max(a,b) ((a > b) ? a : b)

long long n, x[N], s[N], ans[N], l, max_safety;

int main()
{
	scanf("%lld%lld", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%lld", &x[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &s[i]), ans[i] = s[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (x[i] - x[j] > l)
				ans[i] = max(ans[i], ans[j] + s[i]);

	for (int i = 0; i < n; i++)
		max_safety = max(max_safety, ans[i]);

	printf("%lld", max_safety);

	return 0;
}