#include <stdio.h>
#include <stdlib.h>

int minindex;
int minx;
int miny=500000000;
void copyelement(int a[][3], int b[][3], int i, int j){
    a[i][0]=b[j][0];
    a[i][1]=b[j][1];
    a[i][2]=b[j][2];
}
int mod(int n){
    if(n<0) return -1*n;
    return n;
}
//returns quadrant of the point
int q(int x, int y){
    if(x>0 && y>=0) return 1;
    if(x<=0 && y>0) return 2;
    if(x<0 && y<=0) return 3;
    return 4;
}
float slope(int x, int y){
    return (float)y/(float)x;
}
//special merge sort to sort points on the basis of quadrant and slopes
void merge(int a[][3], int l, int m, int r){
    int nl=m-l+1;
    int nr=r-m;
    int i;
    int left[nl][3], right[nr][3];
    for(i=0;i<nl;i++){
        copyelement(left,a,i,l+i);
    }
    for(i=0;i<nr;i++){
        copyelement(right,a,i,m+i+1);
    }
    i=0;
    int j=0, k=l, ql, qr;
    while(i<nl && j<nr){
        ql=q(left[i][1],left[i][2]);
        qr=q(right[j][1],right[j][2]);
        if(ql<qr){
            copyelement(a,left,k,i);
            i++;
        }
        else if(qr<ql){
            copyelement(a,right,k,j);
            j++;
        }
        else{
            float sl=slope(left[i][1],left[i][2]);
            float sr=slope(right[j][1],right[j][2]);
            if(sl<sr){
                copyelement(a,left,k,i);
                i++;
            }
            else if(sr<sl){
                copyelement(a,right,k,j);
                j++;
            }
            else{
                //choosing the one with the closer manhattan distance
                int ml=abs(left[i][1])+abs(left[i][2]);
                int mr=abs(right[j][1])+abs(right[j][2]);
                if(ml<mr){
                    copyelement(a,left,k,i);
                    i++;
                }
                else{
                    copyelement(a,right,k,j);
                    j++;
                }
            }
        }
        k++;
    }
    //insert leftover elements
    while(i<nl){
        copyelement(a,left,k,i);
        i++;
        k++;
    }
    while(j<nr){
        copyelement(a,right,k,j);
        j++;
    }
}

void partition(int a[][3], int l, int r){
    if(l>=r) return;
    int m= (l+r)/2;
    partition(a,l,m);
    partition(a,m+1,r);
    merge(a,l,m,r);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n][3],b[n-1][3];
    for(i=0;i<n;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        if(a[i][2]<miny){
            minindex=a[i][0];
            miny=a[i][2];
            minx=a[i][1];
        }
    }
    int j=0;
    for(i=0;i<n;i++){
        if(a[i][0]!=minindex){
            b[j][0]=a[i][0];
            b[j][1]=a[i][1]-minx;
            b[j][2]=a[i][2]-miny;
            j++;
        }
    }
    partition(b,0,n-2);
    for(i=0;i<n-1;i++){
        printf("%d", b[i][0]);
        if(i!=n-2) printf(" ");
    }
    return 0;
}
