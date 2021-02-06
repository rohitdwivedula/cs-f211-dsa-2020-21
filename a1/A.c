#include<stdio.h>
#define TRUE 1
#define FALSE 0

int isMatch(char* text, int i, char* query){
	for(int k=0; query[k] != 0; k++){
		if(text[i+k] != query[k]) return FALSE;
	}
	return TRUE;
}

int main(){
	char query[] = "baab";
	char text[501];
	int N;
	scanf("%d", &N);
	scanf("%s", text);
	int firstMatch = TRUE; 

	for(int i=0;i<=N-4;i++){
		if(isMatch(text, i, query)){
			if(firstMatch){
				printf("YES %d", i+1);
				firstMatch = FALSE;
			}
			else{
				printf(" %d", i+1);
			}
		}
	}
	if(firstMatch){
		printf("NO");
	}
	return 0;
}