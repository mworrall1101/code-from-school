/* strings_and_pointers.c

   B. Bird - 05/31/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* read_line(f, buffer, buffer_size)
   Read one line from the provided file f into the array
   buffer. No more than buffer_size-1 characters will be read
   from the file, and the resulting string in buffer will be
   null terminated.

   The trailing \n character will not be appended to the
   string stored in buffer.

   If no characters could be read due to EOF being reached,
   the function returns 0. If any characters were successfully
   read (even if EOF was reached afterwards), the function
   returns the number of characters successfully read, including
   any '\n' characters.

   Pre-conditions:
     f is a valid file pointer, referring to an open file
     in read mode.
     buffer is a valid pointer to a character array of size
     at least buffer_size.
   Post-conditions:
     buffer contains a null-terminated string.
*/
int read_line(FILE* f, char buffer[], int buffer_size){
	int i = 0;
	int c = fgetc(f);
	while( (c != EOF) && (c != '\n') && (i < buffer_size-1) ){
		buffer[i] = c;
		i++;
		c = fgetc(f);
	}
	int count = i;
	if (c == '\n')
		count++;
	buffer[i] = '\0';
	return count;
}


/* capitalize every character of the provided string */
void capitalize(char *string){
	int i = 0;
	while (string[i] != '\0'){
		string[i] = toupper(string[i]);
		i++;
	}
}

char* capitalize2(char *string){
	int length = strlen(string);
	char* new_string = (char*)malloc( (length + 1)*sizeof(char) );

	strcpy(new_string, string);

	int i = 0;
	while (new_string[i] != '\0'){
		new_string[i] = toupper(new_string[i]);
		i++;
	}
	new_string[length] = '\0';
	return new_string;
}



int main(){
	//To signal EOF when providing input from the keyboard,
	//type Ctrl-D.
	printf("Enter a line of text:\n");	
	char buffer[100];
	read_line(stdin,buffer,100);
	
	char* s1 = buffer;
	char* s2;
	//s2 = s1;
	//capitalize(s2);
	s2 = capitalize2(s1);
	printf("Original text: \"%s\"\n", s1);
	printf("Capitalized  : \"%s\"\n", s2);
	return 0;
}
