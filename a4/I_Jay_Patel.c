#include<stdio.h>


int fact(int n) {   
    int f=1;
    for(int i=1;i<=n;i++) {
      f*=i;
      f%=1000000007;
    }
    return f;
} 

int main() {
    int n,x,pos;
    scanf("%d %d %d",&n,&x,&pos);
 
    int l=0,r=n,m,cnt=n-x,cnt1=x-1,ans=1;

    while(l<r) {
          m = (l+r)/2;
          if(m<pos) { 
            ans*= cnt1;
            ans%=1000000007;
            cnt1--;
            l=m+1;
          } else if (m==pos) {
            l=m+1;
          } else {
            ans*= cnt;
            ans%=1000000007;
            cnt--;
            r=m;
          }
    }
 
    ans*= fact(cnt+cnt1);
    ans%=1000000007;
    printf("%d",ans);
 
return 0;
}
