#include <stdio.h>
#include <stdlib.h>
//implementing this using merge sort

//declaring it as a global variable to avoid errors
int k;


void merge(int a[],int l, int m, int r){
    int nl=m-l+1;
    int nr=r-m;
    //creating copies of the array in order to compare and merge in original array a
    int left[nl], right[nr];
    for(int i=0;i<nl;i++)
        left[i]=a[l+i];
    for(int i=0;i<nr;i++)
        right[i]=a[m+i+1];
    int lp=0, rp=0, ap=l;
    while(lp<nl && rp<nr){
        //left has lesser mod
        if((left[lp]%k)<(right[rp]%k)){
            a[ap]=left[lp];
            lp++;
        }
        //right has lesser mod
        else if((right[rp]%k)<(left[lp]%k)){
            a[ap]=right[rp];
            rp++;
        }
        //both are equal
        else{
            if(left[lp]<=right[rp]){
                a[ap]=left[lp];
                lp++;
            }
            else{
                a[ap]=right[rp];
                rp++;
            }
        }
        ap++;
    }
    //merging leftover elements
    while(lp<nl){
        a[ap]=left[lp];
        lp++;
        ap++;
    }
    while(rp<nr){
        a[ap]=right[rp];
        rp++;
        ap++;
    }

}

void partition(int a[], int l, int r){
    if(l>=r){
        return;
    }
    int m=(l+r)/2;
    partition(a,l,m);
    partition(a,m+1,r);
    merge(a,l,m,r);

}


int main()
{
    int n,i;
    scanf("%d %d", &n, &k);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    partition(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}
