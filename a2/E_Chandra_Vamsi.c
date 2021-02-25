#include <stdio.h>

#define N (int)1e5 + 5
int n, k;
char c[30], ans[N];

void recur (int pos)
{
	if (pos == k)
	{
		printf("%s\n", ans);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		ans[pos] = c[i];
		recur(pos + 1);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", c);

	recur(0);

	return 0;
}