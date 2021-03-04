#include <stdio.h>
#include <stdlib.h>
#define new_max(x, y) ((x >= y) ? x : y)
#define new_min(x, y) ((x >= y) ? y : x)

/**
 * For eg, if we have n = 10 and string = AABBCCAACA
 * arr[] = {0, 0, 1, 1, 2, 2, 0, 0, 2, 0} (we did arr[i] = (int)string[i] - 65)
 * we remove all consecutive duplicates and store the no of times they repeat  
 * in this case: 
 * no_dup_string = {0, 1, 2, 0, 2, 0}
 * no_dup_count = {2, 2, 2, 2, 1, 1}
 * then we simply traverse through all subarrays of arr[] of length count (no of letters)
 * and if all elements of that subarray is unique we generate the actual length of this subarray by using no_dup_count[]
 * final answer is the minimum length of all such subarrays
**/

void clear(int notes[], int n) {
    for (int i=0; i<n; i++) {
        notes[i] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char string[n];
    scanf("%s", &string);
    int count = 0;
    int notes[7] = {0}, arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = (int)string[i] - 65;
        count += (notes[arr[i]] == 0) ? 1 : 0;
        notes[arr[i]] = 1;
    }
    if (count <= 2) {
        printf("%d", count);
        return 0;
    }
    // generating a string (no_dup_string) without any consecutive duplicates and a frequency array (no_dup_count)
    int i = 0, no_dup_size = 0;
    int no_dup_string[n], no_dup_count[n];
    while (i < n) {
        int j = i + 1, tmp = 1;
        while (arr[j] == arr[i]) {
            tmp++;
            j++;
        }
        no_dup_string[no_dup_size] = arr[i];
        no_dup_count[no_dup_size] = tmp;
        no_dup_size++;
        i = j;
    }

    // traversing on all substrings of length count (no of letters)
    // if the string has all letters unique then its a valid string, we need to find such a string of least length
    int ans = n;
    for (i=0; i<no_dup_size - count + 1; i++) {
        clear(notes, 7);
        int tmp = 0;
        for (int j=i; j<i+count; j++) {
            tmp += (notes[no_dup_string[j]] == 0) ? 1 : 0;
            notes[no_dup_string[j]] = 1;
        }
        if (tmp == count) {
            tmp = 0;
            for (int j=i+1; j<i+count-1; j++) {
                tmp += no_dup_count[j];
            }
            ans = new_min(ans, tmp + 2);
        } 
    }
    printf("%d", ans);
}