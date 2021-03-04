#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char riff[n+1];
	scanf("%s", riff);
	int notes[7];
	int i;
	int min_length = n;
	int notes_present = 0;
	for(i = 0; i < 7; i++) notes[i] = 0;
	for(i = 0; i < n; i++) {
		if(!notes[riff[i]-'A']) notes_present++;
		notes[riff[i]-'A']++;
	}
	int start_index = 0;
	int end_index = n-1;
	while(start_index <= end_index+notes_present) {
		i = -1;
		while(riff[start_index+ (++i)] == riff[end_index-i]);
		start_index += i;
		char cs = riff[start_index]-'A';
		char ce = riff[end_index]-'A';
		
		if(notes[cs] > notes[ce]) {
			start_index++;
			min_length--;
			notes[cs]--;
		}
		else {
			if(notes[cs] == notes[ce] && notes[cs] == 1) break;
			end_index--;
			min_length--;
			notes[ce]--;
		}
	}
	
	printf("%d", min_length);

	return 0;
}