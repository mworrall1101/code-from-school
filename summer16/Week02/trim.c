/* trim.c


   B. Bird - 05/11/2016
*/

#include <stdio.h>

/* trim(s)
   Remove all leading and trailing whitespace characters
   from the string s. Whitespace characters include
   spaces, newlines and tabs. The function isspace(c)
   in ctype.h will return true if the character c
   is whitespace.

   Pre-conditions:
     s is a valid, null terminated C string.
   Post-conditions:
     s has been modified to remove all leading and trailing
     whitespace, but is still a null terminated C string.
*/
void trim(char s[]){

}

int main(){
	char s[] = "  Hello World \n  ";
	printf("The string is '%s'\n", s);
	printf("Calling trim.\n");
	trim(s);
	printf("The string is '%s'\n", s);
	return 0;
}
