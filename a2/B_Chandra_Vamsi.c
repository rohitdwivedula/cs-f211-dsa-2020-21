#include <stdio.h>

#define N 1001
#define max(a,b) ((a > b) ? a : b)

int n, m, cnt, adj[N][N], visited[N], mx;

void dfs(int v)
{
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
		if (adj[v][i] && !visited[i])
			dfs(i), cnt++;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x][y] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		cnt = 1;
		for (int j = 1; j <= n; j++)
			visited[j] = 0;
		dfs(i);
		mx = max(mx, cnt);
	}

	printf("%d", mx);

	return 0;
}