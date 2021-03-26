#include <stdio.h>
#define max(a, b) (a>b ? a : b)
#define min(a, b) (a>b ? b : a)


int main() {
	int n;
	scanf("%d",&n);

	int a[n], mx = -1e6, mn = 1e6;
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int cntmx = 0, cntmn = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == mx) 
			cntmx++;
		else if(a[i] == mn) 
			cntmn++;
	}

	printf("%d %d",mx-mn, cntmx*cntmn);
}