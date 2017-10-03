/* files.c


   B. Bird - 05/13/2016
*/

#include <stdio.h>
#include <ctype.h>

int main(){
	FILE* f = fopen("fruit.txt","r");
	if (f == NULL){
		printf("Couldn't open the file\n");
		return 0;
	}
	
	int c;
	c = fgetc(f);
	while(c != EOF){
		//printf("Character: %c\n", (char)c );
		char d = toupper(c);
		printf("%c", d );
		c = fgetc(f);
	}

	fclose(f);
	return 0;
}
