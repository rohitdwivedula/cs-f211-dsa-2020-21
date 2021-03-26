#include <stdio.h>
int main()
{
	int N, T, i, rs = 0, I ;
	scanf("%d %d", &N, &T);
	int A[N];
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(i = 0; i < T; i++)
	{
		scanf("%d", &I);
		rs += I ;
		printf("%d %d\n", A[rs%N], A[(rs-1)%N]);
	}		
}
