#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n, int r){
    int maxim=r;
    int left=2*r+1;
    int right=2*r+2;
    if(left<n && a[left]>a[maxim])
        maxim=left;
    if(right<n && a[right]>a[maxim])
        maxim=right;
    if(maxim!=r){
        int temp=a[r];
        a[r]=a[maxim];
        a[maxim]=temp;
        heapify(a,n,maxim);
    }


}

void chocolate(int n, int a[], int k){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(a,n,i);
    }
    int sum=0;
    sum+=a[0];
    for(int i=0;i<k-1;i++){
        a[0]=a[0]/3;
        heapify(a,n,0);
        sum+=a[0];
    }
    printf("%d",sum);
}

int main()
{
    int n,k;
    scanf("%d %d", &n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    chocolate(n,a,k);
    return 0;
}
