#include <stdio.h>

int abs(int a) {
	if(a > 0)
		return a;
	else 
		return -a;
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int b[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i],&a[j]);
			swap(&b[i],&b[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	swap(&b[i+1],&b[high]);
	return (i+1);
}
void quicksort(int a[], int b[], int low, int high) {
	if(low < high) {
		int pivot = partition(a,b,low,high);
		quicksort(a,b,low,pivot-1);
		quicksort(a,b,pivot+1,high);
	}
	return;
}
int main() {
	int n;
	scanf("%d",&n);
        int x1[n],x2[n],y1[n],y2[n];
        int cnt1 = 0, cnt2 = 0;
	for(int i  = 0; i < n; i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		// 1st and 4th quadrant
		if(x >= 0) {
			x1[cnt1]=x;
			y1[cnt1]=y;
			cnt1++;
		} // 2nd and 3rd quadrant 
		else if(x < 0) {
			x2[cnt2]=x;
			y2[cnt2]=y;
			cnt2++;
		} 
	}
        // sorting the points according to the y coordinate
	quicksort(y1,x1,0,cnt1-1);
	quicksort(y2,x2,0,cnt2-1);
        int ans = 0;
        // manhattan distance calculation in 1st and 4th quadrant
	for(int i = 0; i < cnt1-1; i++) {
            ans += abs(x1[i+1]-x1[i]) + abs(y1[i+1]-y1[i]);
	}
        // manhattan distance calculation in 2nd and 3rd quadrant
	for(int i = 0; i < cnt2-1; i++) {
            ans += abs(x2[i+1]-x2[i]) + abs(y2[i+1]-y2[i]);
	}
	// manhattan distance calculation of the edge connection 1st and 2nd quadrant
	ans += abs(x1[cnt1-1]-x2[cnt2-1]) + abs(y1[cnt1-1]-y2[cnt2-1]);
	// manhattan distance calculation of the edge connection 3rd and 4th quadrant
	ans += abs(x1[0]-x2[0]) + abs(y1[0]-y2[0]);
	printf("%d",ans);

	return 0;

}
