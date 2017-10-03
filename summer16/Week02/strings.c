/* strings.c


   B. Bird - 05/10/2016
*/

#include <stdio.h>

/* string_length(string)
   Return the number of characters in string, excluding
   the null terminator.

   Pre-conditions:
     string is a valid, null terminated C string.
   Return value:
     The length of string (excluding the null terminator).
*/
int string_length(char string[]){
	int i = 0;
	//Iterate through the string until the null
	//terminator is found.
	while(string[i] != '\0'){
		i++;
	}
	return i;
}

int main(){
	char s[] = "Hello World";
	printf("The string is '%s'\n", s);
	printf("Changing character s[1] to E...\n");
	s[1] = 'E';
	printf("The string is '%s'\n", s);

	printf("The length of the string is %d\n", string_length(s));
	return 0;
}
