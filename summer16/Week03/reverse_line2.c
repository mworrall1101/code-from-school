/* reverse_line.c

   Read lines of text from standard input and print the reversal
   of each line to standard output.

   B. Bird - 05/17/2016
*/

#include <stdio.h>
#include <string.h>

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

/* reverse_string(s)
   Reverse the null-terminated string s.

   Pre-conditions:
     s is a null terminated C string.
   Post-conditions:
     The text in s has been reversed (the length of s will be unchanged)
*/
void reverse_string(char s[]){
	int length = strlen(s);
	int i;
	for(i = 0; i < length/2; i++){
		char c = s[i];
		s[i] = s[length-i-1];
		s[length-i-1] = c;
	}
}


int main(){
	//To signal EOF when providing input from the keyboard,
	//type Ctrl-D.	
	char buffer[100];
	while( read_line(stdin, buffer,100) > 0 ){
		reverse_string(buffer);
		printf("%s\n",buffer);
	}

	return 0;
}
