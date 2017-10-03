/* read_line.c


   B. Bird - 05/13/2016
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
}

int main(){
	// Add some test cases for read_line here...
	// (Consider writing a loop which reads every
	//  line in a file)
	return 0;
}
