/* duplicate_string.c

   B. Bird - 06/17/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/* capitalize(string)
   Modify the provided string to convert each lowercase letter
   to uppercase

   Pre-conditions:
     string is a valid null terminated C string.
   Post-conditions:
     All lowercase letters in string have been converted to uppercase.
*/
void capitalize(char *string){
	int i = 0;
	while (string[i] != '\0'){
		string[i] = toupper(string[i]);
		i++;
	}
}

/* duplicate_string(s)
   Create a new, dynamically allocated copy of the string s
   and return it.

   Note: The POSIX library function strdup() is also available
         for this purpose, and should be useable on any unix-based
	 machine.

   Pre-conditions:
     s is a valid null terminated C string
   Return value:
     A newly allocated string containing a copy of s.
     The string will have been allocated with malloc, and
     it is the caller's responsibility to ensure that the
     returned string is eventually deallocated with free().
*/
char* duplicate_string(char* s){

	int length = strlen(s);
	char* new_string = (char*)malloc(sizeof(char)*(length+1));
	strcpy(new_string,s);

	return new_string;
}



int main(){
	char s1[] = "Hello World";
	char* s2;
	s2 = duplicate_string(s1);
	capitalize(s2);
	printf("Original text: \"%s\"\n", s1);
	printf("Capitalized  : \"%s\"\n", s2);
	return 0;
}
