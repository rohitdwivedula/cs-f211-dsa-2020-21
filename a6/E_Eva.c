#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//merge function for this specific question
void merge(int c[][2],int l, int m, int r){
    int nl=m-l+1;
    int nr=r-m;
    int left[nl][2],right[nr][2],i;
    for(i=0;i<nl;i++){
        left[i][0]=c[l+i][0];
        left[i][1]=c[l+i][1];
    }
    for(i=0;i<nr;i++){
        right[i][0]=c[m+i+1][0];
        right[i][1]=c[m+i+1][1];
    }
    int lp=0,rp=0,cp=l;
    while(lp<nl && rp<nr){
        if(left[lp][1]<right[rp][1]){
            c[cp][0]=left[lp][0];
            c[cp][1]=left[lp][1];
            lp++;
        }
        else if(right[rp][1]<left[lp][1]){
            c[cp][0]=right[rp][0];
            c[cp][1]=right[rp][1];
            rp++;
        }
        else{
            if(left[lp][0]<=right[rp][0]){
                c[cp][0]=left[lp][0];
                c[cp][1]=left[lp][1];
                lp++;
            }
            else{
                c[cp][0]=right[rp][0];
                c[cp][1]=right[rp][1];
                rp++;
            }
        }
        cp++;
    }
    while(lp<nl){
        c[cp][0]=left[lp][0];
        c[cp][1]=left[lp][1];
        lp++;
    }
    while(rp<nr){
        c[cp][0]=right[rp][0];
        c[cp][1]=right[rp][1];
        rp++;
    }
}

void partition(int c[][2], int l, int r){
    if(l>=r) return;
    int m=(l+r)/2;
    partition(c,l,m);
    partition(c,m+1,r);
    merge(c,l,m,r);
}

int main()
{
    int n,c,d,k,i;
    scanf("%d %d %d %d",&n,&c,&d,&k);
    float a[n][2];
    int ca[c],da[d];
    for(i=0;i<c;i++)
        ca[i]=0;
    for(i=0;i<d;i++)
        da[i]=0;
    for(i=0;i<n;i++){
        scanf("%f %f",&a[i][0],&a[i][1]);
        ca[(int)a[i][0]]++;
        da[(int)a[i][1]]++;
    }
    int count[n][2];
    for(i=0;i<n;i++){
        count[i][0]=i;
        count[i][1]=ca[(int)a[i][0]]*da[(int)a[i][1]];
    }
    partition(count,0,n-1);
    for(i=0;i<k;i++){
        printf("%d",count[i][0]);
        if(i!=k-1) printf(" ");
    }
    return 0;
}
