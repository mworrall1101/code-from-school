/* get_nth.c

    University of Victoria, Dept. of Computer Science

    SENG 265 Lab, Summer 2016

    Written by Tom Arjannikov
*/


#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


// Returns the memory address of n-th word in a string
// Returns memory address of '\0', if it is reached before n-th word
// Assumes the input is a valid c-string (could be empty)
char* find_nth(char* str, int n) {

	char* new_str = str;
	int s_len = strlen(str);
	int w_cnt = 0;
	int new_word = 1;   // flag

	for(int i=0; i<=s_len; i++) {
		new_str = &(str[i]);
		if(isspace(str[i])) {   // ignore whitespace
			new_word = 1;
			continue;
		}
		if(new_word) {  // count number of words
			new_word = 0;
			if(w_cnt == n) 
				break;
			w_cnt++;
		}
	}

	return new_str;
}


// Returns the number of characters between str[0] and whitespace or '\0'
// Assumes the input is a valid c-string (could be empty)
int char_count(char* str) {

	int count = 0;
    while(str[count] != '\0') {
        if(isspace(str[count]))
            break;
        count++;
    }

	return count;
}


// Returns a pointer to NEW memory on heap with a copy of input string
// Assumes the input is a valid c-string (could be empty)
// The user is responsible to free() this memory later
char* copy_word(char* str) {

    int cnt = char_count(str);
    // note: type-casting is unnecessary here, but some consider it good practice
    char* new_str = (char*) malloc(sizeof(char)*(cnt+1));
	memcpy(new_str, str, cnt);
	new_str[cnt]='\0';

    return new_str;
}


int main() {

//	char* str = "";
	char* str = "     Th\0is    is a\ttemporary    string          .";
	int n = 0;

	char* nth_str = find_nth(str, n);
	printf("\n%s\n", nth_str);

	int count = char_count(nth_str);
	printf("\nCount = %d\n", count);

    char * cpy_str = copy_word(nth_str);
	printf("Copy is: %s.\n", cpy_str);

    // clean-up
	free(cpy_str);
	cpy_str = NULL;

	return 0;
}
