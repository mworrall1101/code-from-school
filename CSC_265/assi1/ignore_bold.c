/* ignore_bold.c
 Mark Worrall - 05/30/2016
*/

#include <stdio.h>
#include <string.h>




int main() {

	FILE* input = stdin;
	int i, c, end,  count = 0;
	char str[1000];
	
	while(c != EOF) {
		c = fgetc(input);
		while((c != '\n') && (c != EOF)) {
			str[count] = c;
			count++;
			c = fgetc(input);
		}
		str[count] = '\0';
		count = 0;
		while(strstr(str, "<b>")) {
		
			while(str[count+2] != '\0') {
				end = 1;
				if((str[count] == '<') && (str[count+1] == 'b') && (str[count+2] == '>' )) {
					i = 0;
					while((end) && (str[i+2] != '\0')) {
						i++;
						if((str[i] == '/') && (str[i+1] == 'b') && (str[i+2] == '>')){
							end = 0;
						}
					}
					i+=3;
					while(str[i] != '\0'){
						str[count] = str[i];
					i++;
					count++;
					}
					str[count] = '\0';
				}

				i++;
				count++;
			}
			printf("%s\n", str);
		}
		
	}
	return 0;
}
