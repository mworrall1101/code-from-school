/* ignore_bold.c
   
   SENG 265 - Summer 2016
   Quiz 1 (Array-based solution)
   
   
   B. Bird - 05/25/2016
*/

#include <stdio.h>
#include <stdlib.h>

/* Returns 1 if the substring occurs in the string starting at the provided index */
int substring_at_index(char* string, char* substring, int index){
	int i = 0;
	while(string[i+index] != '\0' && substring[i] != '\0' && substring[i] == string[i+index])
		i++;
	if(substring[i] == '\0')
		return 1;
	return 0;
	
}

int main(int argc, char* argv[]){

	char line[101];
	int ignoring = 0;
	while(fgets(line,101,stdin)){
		int i = 0;
		while(line[i] != '\0'){
			if (ignoring){
				if(substring_at_index(line,"</b>",i)){
					i += 4;
					ignoring = 0;
				}else{
					i++;
				}
			}else{
				if(substring_at_index(line,"<b>",i)){
					i += 3;
					ignoring = 1;
				}else{
					printf("%c",line[i]);
					i++;
				}
			}	
		}		
	}

	return 0;
}
