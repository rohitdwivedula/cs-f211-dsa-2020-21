#include<stdio.h>

int main(){
	char n1[1002], n2[1002], n3[1002];
	scanf("%s %s", n1, n2);
	
	// fill n3 with null characters
	for(int i=0;i<=1001;i++) n3[i] = 0;

	// calculate l1 and l2, the lengths of strings n1 and n2
	int l1 = 0, l2 = 0, k=0;
	while(n1[k] != 0){
		k++;
	}
	l1 = k;

	k = 0;
	while(n2[k] != 0){
		k++;
	}
	l2 = k;
	
	// perform digitwise addiiton from LSB to MSB
	int carry = 0;

	k=1000; // index for n3
	
	for(int i=l1-1,j=l2-1; i>=0 || j>=0; i--, j--, k--){
		int dig_sum;
		if(j>=0) dig_sum = (n1[i]-'0') + (n2[j]-'0') + carry;
		else dig_sum = (n1[i]-'0') + carry;
		n3[k] = '0' + (dig_sum)%10;
		carry = dig_sum/10;
	}
	if(carry){
		n3[k] = '0' + carry;
	}

	int i = 0;
	while(n3[i] == 0) i++;
	printf("%s", &n3[i]);
	return 0;
}


/*
TESTCASES

Input
736478265827647826487264782648723647832647832648732648723 
3427364786487236478236487326487264872468327

Output
736478265827651253852051269885201884319974319913605117050
*/