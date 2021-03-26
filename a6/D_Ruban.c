#include <stdio.h>
int main()
{
	int N, k, X, i, j, a = 0, m ;
	scanf("%d %d %d", &N, &k, &X);
	int S[N], r[k], t[N], rs[N-X+1];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &S[i]);
		a += S[i];
		t[i] = 0 ;
		if(i < N-X+1)
			rs[i] = 0 ;
	}
	for(i = 0; i < k; i++)
	{
		scanf("%d", &r[i]);
		t[r[i]] = S[r[i]];
		a -= S[r[i]];
	}
	printf("%d ", a);
	for(i = 0; i < X; i++)
		rs[0] += t[i];
	m = rs[0];
	for(i = 1; i < N-X+1; i++)
	{
		rs[i] = rs[i-1]+t[i+X-1]-t[i-1];
		if(m < rs[i])
			m = rs[i];	// finding out the timeframe where the backup machine can scan the maximum number of ID cards
	}
	a += m ;
	printf("%d", a);
}
