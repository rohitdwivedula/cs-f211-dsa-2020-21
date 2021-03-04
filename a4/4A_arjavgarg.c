#include <stdio.h>

int lin_search(char alphs[26], char ch) {
	int i;
	for(i = 0; i < 26; i++) if(alphs[i] == ch) return i;
	return -1;
}

int first_empty_before(char alphs[26], int index) {
	int i = index-1;
	for(; i >= 0; i--) {
		if(alphs[i] == 0) return i;
	}
	return -1;
}

int first_empty_after(char alphs[26], int index) {
	int i = index+1;
	for(; i < 26; i++) {
		if(alphs[i] == 0) return i;
	}
	return -1;
}

int move_and_insert_after(char alphs[26], int index, char to_insert) {
	int i = first_empty_before(alphs, index);
	if(i == -1) return -1;
	for(; i < 25; i++) {
		alphs[i] = alphs[i+1];
	}
	alphs[25] = to_insert;
}

int move_and_insert_before(char alphs[26], int index, char to_insert) {
	int i = first_empty_after(alphs, index);
	if(i == -1) return -1;
	for(; i >= 0; i--) {
		alphs[i+1] = alphs[i];
	}
	alphs[0] = to_insert;
}

int main() {
	int n;
	scanf("%d", &n);
	char alphs[26];
	int i;
	for(i = 0; i < 26; i++) alphs[i] = 0;
	
	for(i = 0; i < n; i++) {
		char u, v;
		scanf("\n%c %c", &u, &v);
		if(u == v) {
			printf("ALIENS BE CRAZY");
			return 0;
		}
		int u_pos = lin_search(alphs, u);
		int v_pos = lin_search(alphs, v);
		if(u_pos != -1) {
			if(v_pos != -1) {
				if(u_pos > v_pos) {
					printf("ALIENS BE CRAZY");
					return 0;
				}
			}
			else {
				int v_insertion = first_empty_after(alphs, u_pos);
				if(v_insertion == -1) {
					move_and_insert_after(alphs, u_pos, v);
				}
				else {
					alphs[v_insertion] = v;
				}
			}
		}
		else {
			if(v_pos != -1) {
				move_and_insert_before(alphs, v_pos, u);
			}
			else {
				alphs[first_empty_after(alphs, -1)] = u;
				alphs[first_empty_before(alphs, 26)] = v;
			}
		}
	}
	
	for(i = 0; i < 26; i++) if(alphs[i]) printf("%c", alphs[i]);
	
	return 0;
}