#include <stdio.h>
#include <string.h>

void swap(long long *x, long long *y) { 
	long long temp = *x; 
	*x = *y; 
	*y = temp; 
}

void Heapify(long long cost[], long long n, long long i) {
	long long largest = i;
	long long l = 2*i + 1;
	long long r = 2*i + 2;

	if(l < n && cost[largest] < cost[l]) 
		largest = l;

	if(r < n && cost[largest] < cost[r])
		largest = r;

	if(largest != i) {
		swap(&cost[i],&cost[largest]);
		Heapify(cost, n, largest);
	}

	return;
	
}


void Build_Heap(long long cost[], long long n) {

	long long start = n/2 - 1;

	for(long long i = start; i >= 0; i--) {
		Heapify(cost, n, i);
	}

	return;                                                                                       
}

long long Cost(long long cost[], long long m) {
	long long ans = cost[0];
	cost[0] = cost[m-1];
	Heapify(cost, m-1, 0);
	return ans;
}

int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	long long cost[n];
	memset(cost,0,sizeof(cost));

	for(int i = 0; i < n; i++) {
		char s[151]={};
		scanf("%s",s);
		for(int j = 151; j >= 0; j--) {
			if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
				continue;
			else {  
				long long  num = 0, k = 1;
				while(j >= 0 && s[j] >= '0' && s[j] <= '9') {
                                        num += k*(s[j]-'0');
                                        k *= 10;
					j--;
				}
				cost[i] += num;

			} 

		} 
			
	}

	Build_Heap(cost,n);

        long long ans = 0, m = n;
	for(int i = 0; i < k; i++) {
		ans += Cost(cost,m);
		ans %= (1000000007);
		m--;
	}
	printf("%lld",ans);
	return 0;
}