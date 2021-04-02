#include <stdio.h>

int main() {
	char n1[201]={}, n2[201]={}, merge[401]={};
	scanf("%s\n%s",n1,n2);

        int i = 0, j = 0, k = 0;

	while(n1[i] != '\0' && n2[j] != '\0') {
		if(n1[i] > n2[j]) {
			merge[k] = n1[i];
			i++;
			k++;
		} else if(n1[i] < n2[j]){
			merge[k] = n2[j];
			j++;
			k++;
		} else {
			int l1 = i+1, l2 = j+1, check = 0;
			while(n1[l1] != '\0' && n2[l2] != '\0') {
				if(n1[l1] == n2[l2]) {
					l1++, l2++;
					continue;
				} else if(n1[l1] > n2[l2]) {
					check = 1;
					merge[k] = n1[i];
					i++;
					k++;
					break;
				} else {
					check = 1;
					merge[k] = n2[j];
					j++;
					k++;
					break;
				}
			} 

			if(check == 0) {
				if(n1[l1] == '\0' && n2[l2] == '\0') {
					while(n1[i] != '\0') {
						merge[k] = n1[i];
						i++;
						k++;
					}
					while(n2[j] != '\0') {
						merge[k] = n2[j];
						j++;
						k++;
					}
					break;
				}
				else if(n1[l1] == '\0' && n2[l2] >= n2[j]) {
					merge[k] = n2[j];
					j++;
					k++;
				} else if(n2[l2] == '\0' && n1[l1] >= n1[i]) {
					merge[k] = n1[i];
					i++;
					k++;
				} else if(n2[l2] == '\0' && n1[l1] < n1[i]) {
					merge[k] = n2[j];
					j++;
					k++;
				} else if(n1[l1] == '\0' && n2[l2] < n2[j]) {
					merge[k] = n1[i];
					i++;
					k++;
				}
			}
		}
	}
	while(n1[i] != '\0') {
		merge[k] = n1[i];
		i++;
		k++;
	}

	while(n2[j] != '\0') {
		merge[k] = n2[j];
		j++;
		k++;
	}
	printf("%s",merge);

}