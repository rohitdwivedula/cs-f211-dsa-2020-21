#include <stdio.h>
long long hcf(long long x, long long y);
long long lcm(long long x, long long y);
long long mindex(long long s, long long arr[]);
int main()
{
	long long N, k, i, l , time, m, r = 0 ;
	scanf("%lld %lld", &N, &k);
	if(N == 1)
	{
		long long t ;
		scanf("%lld", &t);
		printf("%lld", k*t);
		return 0 ;
	}	
	long long t[N], w[N];
	scanf("%lld %lld", &t[0], &t[1]);
	w[0] = 0 ;
	w[1] = 0 ;
	l = lcm(t[0], t[1]);
	for(i = 2; i < N; i++)
	{
		scanf("%lld", &t[i]);
		l = lcm(l, t[i]);
		w[i] = 0 ;
	}
	for(i = 0; i < N; i++)
		r += l/t[i];
	time += l*(k/r);
	k %= r ;
	while(k--)
	{
		for(i = 0; i < N; i++)
			w[i] += t[i];	// finding out the possible time taken after crushing each watermelon
		m = mindex(N, w);	// finding which machine would give the least time taken, when k-1 watermelons are pending
		for(i = 0; i < N; i++)
		{
			if(i == m)
				continue ;
			w[i] -= t[i];	// reversing the time added
		}
	}
	m = 0 ;
	for(i = 1; i < N; i++)
	{
		if(w[i] > w[m])
			m = i ;
	}
	time += w[m];
	printf("%lld", time);
}
long long hcf(long long x, long long y)
{
	if(y == 0)
		return x ;
	return hcf(y, x%y);
}
long long lcm(long long x, long long y)
{
	return (x*y)/hcf(x,y);
}
long long mindex(long long s, long long arr[])
{
	int x = 0, y ;
	for(y = 1; y < s; y++)
	{
		if(arr[x] > arr[y])
			x = y ;
	}
	return x ;
}
