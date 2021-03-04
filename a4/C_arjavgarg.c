#include <stdio.h>
#include <string.h>

int can_transit(char str[13], char str1[13]) {
	int diff = 0;
	int i;
	int l1 = strlen(str);
	if(l1 != strlen(str1)) {
		return 0;
	}
	
	for(i = 0; i < l1; i++) {
		if(str[i] != str1[i]) {
			diff++;
			if(diff > 1) break;
		}			
	}
	
	if(diff == 1) return 1;
	return 0;
	
}

int is_diff(char str[13], char str2[13]) {
	int i;
	for(i = 0; i < strlen(str); i++) {
		if(str[i] == str2[i]) {
			return 0;
		}
	}
	return 1;
}

int talk_to_self(char str[13], int transitions, int current, int n, char intermediate[n][n], char dic[n][13], char visited[n]) {
	if(visited[current]) return 0;
	visited[current] = 1;
	if(is_diff(str, dic[current])) {
		return transitions;
	}
	int i;
	int min = -1;
	for(i = 0; i < n; i++) {
		if(intermediate[current][i] && !visited[i]) {
			int x = talk_to_self(str, transitions+1, i, n, intermediate, dic, visited);
			if(x){
				if(min == -1) min = x;
				else min = min < x? min : x;
			}
		}
	}
	if(min != -1) return min;
	return 0;
}

int main() {
	int n;
	char s[13];
	scanf("%d", &n);
	scanf("%s", s);
	char dic[n][13];
	int i, j;
	for(i = 0; i < n; i++) {
		scanf("%s", dic[i]);
	}
	
	char intermediate[n][n];
	char visited[n];
	for(i = 0; i < n; i++) {
		visited[i] = 0;
		for(j = i+1; j < n; j++) {
			intermediate[j][i] = intermediate[i][j] = can_transit(dic[i], dic[j]);
		}
	}
	
	int min = -1;
	for(i = 0; i < n; i++) {
		if(can_transit(s, dic[i])) {
			int x = talk_to_self(s, 0, i, n, intermediate, dic, visited);
			if(x) {
				if(min == -1) min = x;
				else min = min > x ? x : min;
			}
		}
	}
	
	printf("%d", min);

	return 0;
}