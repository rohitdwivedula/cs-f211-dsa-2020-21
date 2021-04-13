// #include <stdio.h>
// void main(){
//     int n,k;
//     int i;
    
//     scanf("%d %d",&n,&k);
//     int timetaken_to_crush[n];
//     for(i=0;i<n;i++){
//         scanf("%d",&timetaken_to_crush[i]);
//     }

// }
#include <stdio.h>
#include <limits.h>
 
#define MAX 100000
 
void swap(int a[], int b[]){
    int temp = a[0];
    a[0] = b[0];
    b[0] = temp;
 
    temp = a[1];
    a[1] = b[1];
    b[1] = temp;
}
 
int compare(int a[], int b[]){
    if(a[1] + a[0] < b[1] + b[0])
        return 1;
    return 0;        
}
 
void heap(int arr[][2], int i, int n){
    int left = 2*i + 1, right  = 2*i + 2, num = i;
 
    if(left < n && compare(arr[left], arr[i]) == 1)
        num = left;
    if(right < n && compare(arr[right], arr[num]) == 1)
        num = right;
    
    if(num != i){
        swap(arr[i], arr[num]);
        heap(arr, num, n);
    }
}

void make(int arr[][2], int n){
    for(int i = n/2; i > -1; i--)
        heap(arr, i, n);
}
 
int main(){
    int n,k, num[MAX][2], temp = 0;
    scanf("%d %d",&n,&k);
    for(int i=0; i < n; i++){
        scanf("%d",&num[i][0]);
        num[i][1] = 0;
    }
    make(num, n);
    while(k--){
        num[0][1] += num[0][0];
        heap(num,0,n);
    }
 
    for(int i = 0; i < n; i++)
        if(temp < num[i][1])
            temp = num[i][1];
    
    printf("%d",temp);
 
    return 0;
}       