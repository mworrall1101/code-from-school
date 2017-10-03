/* stream_search.c

	Mark Worrall - 05/23/2016

*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	if(argc < 2){ 
		fprintf(stderr, "Usage: ./stream_search <word list file>\n");
		return -1;
	}

	FILE* input = stdin;
	int count, buffer_size = 1000;
	int c;
	char string[buffer_size];
	int match;
	int numchar, i, j;
	
	
	while(c != EOF){
		input = stdin;
		match = 0;
		count = 0;
		FILE* test_words = fopen(argv[1], "r");	
		if(test_words == NULL) {
			fprintf(stderr, "Error: Unable to open word list\n");
			return -1;
		}	
		int wc = fgetc(test_words);//wc --> word char
		c = fgetc(input);
		while((c != '\n') && (c != EOF) && (count < buffer_size)) {
			string[count] = c;
			c = fgetc(input);
			count++;
		}
		string[count] = '\0';
		
		while((match == 0) && (wc != EOF)) {
		//test each word until the end of the list is reached or a
		// match is found
			i = 0;
			j = 0;
			numchar = 0;
			char word[100];
			while((wc != '\n') && (wc != EOF)) {
			//put word in word array
			//test for word in string
				if(!isspace(wc)) {
					word[i] = wc;
					numchar++;
					i++;	
				}
				wc = fgetc(test_words);	
			}
			wc = fgetc(test_words);
			if(numchar < 1)//skip empty lines in word list
				continue;

			word[i] = '\0';
			i = 0;
			//print string if it contains test word
			while(string[j] != '\0'){
				if((string[j] == word[i]) && (word[i+1] == '\0')) {
					match = 1;
					printf("%s\n", string);
					break;
				} else if(word[i] == string[j]) {
					i++;
				} else if(i > 0){
					j--;
					i = 0;
				} else {
					i = 0;
				}
				j++;
			}
		}
	}
}
