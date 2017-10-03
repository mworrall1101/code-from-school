/* ignore_bold2.c
   
   SENG 265 - Summer 2016
   Quiz 1 (Pointer-based solution)
   
   
   B. Bird - 05/25/2016
*/

#include <stdio.h>
#include <stdlib.h>

int string_startswith(char* s, char* prefix){
	while (*s && *prefix && *s == *prefix){
		s++;
		prefix++;
	}
	if (*prefix)
		return 0;
	return 1;
}

int main(int argc, char* argv[]){

	char line[101];
	int ignoring = 0;
	while(fgets(line,101,stdin)){
		char *s = line;
		while(*s){
			if(ignoring){
				if (string_startswith(s,"</b>")){
					s = s + 4;
					ignoring = 0;
				}else{
					s++;
				}
			}else{
				if (string_startswith(s,"<b>")){
					s = s + 3;
					ignoring = 1;
				}else{
					printf("%c",*s);
					s++;
				}
			}
		}
	}

	return 0;
}
