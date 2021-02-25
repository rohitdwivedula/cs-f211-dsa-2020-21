#include<stdio.h>

/**The program can be done fairly easily in a brute force method.
 * Just check for a prime first (complexity O(n)),
 * and then increment each digit into a number array.
 * Total complexity = O(B^2)
 * **/

int prime(int n){
    for(int i = 2; i < n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void main(){

    int a,b;

    scanf(" %d",&a);
    scanf(" %d",&b);

    int nums[10];
    for(int i = 0; i < 10; i++) nums[i] = 0;

    for(int i = a; i <= b; i++){
        if(prime(i)){
            int temp = i;
            while(temp != 0){
                nums[temp%10]++;
                temp /= 10;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < 10; i++){
        if(nums[i]>nums[max]) max = i; 
    }

    printf("%d %d",max,nums[max]);

}