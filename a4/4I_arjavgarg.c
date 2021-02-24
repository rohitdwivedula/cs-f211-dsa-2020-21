#include <stdio.h>

long long int fac(int x) {
	if(x == 0) return 1;
	return x * fac(x-1);
}

int main() {
	int n, x, pos;
	scanf("%d %d %d", &n, &x, &pos);
	
	long long int perms = 1;
	int less = x-1;
	int more = n-x;
	int l = 0, r = n;
	while(l < r) {
		int M = (l+r)/2;
		if(pos > M) {
			perms *= less;
			less--;
			l = M+1;
		}
		else if(pos < M) {
			perms *= more;
			more--;
			r = M-1;
		}
		else {
			perms *= fac(less + more);
			break;
		}
	}
	
	printf("%d", perms%1000000007);

	return 0;
}