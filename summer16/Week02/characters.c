/* characters.c


   B. Bird - 05/13/2016
*/

#include <stdio.h>
#include <ctype.h>

int main(){
	
	char c;
	printf("Enter a character: ");
	c = getchar();
	printf("After getchar: c = '%c'\n",c);
	c = toupper(c);
	printf("After toupper: c = '%c'\n",c);
	return 0;
}
