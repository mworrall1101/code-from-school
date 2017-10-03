/* reverse_lines.c

   A program to read in every line of standard input, then
   print the lines out in reverse order.

   This version uses the StringStack implementation in string_stack.c,
   by including the header file string_stack.h.

   To compile, use a command like
     gcc -std=c99 -Wall -o reverse_lines2 reverse_lines2.c string_stack.c
  
   B. Bird - 06/10/2016
*/

#include <stdio.h>
#include <string.h>
#include "string_stack.h"

#define MAX_LINE 99

int main(){

	StringStack S;
	S.head = NULL;
	
	char line[MAX_LINE+1];
	
	while(fgets(line,MAX_LINE+1,stdin)){
		StringStack_Push(&S, line);
	}

	while( StringStack_Pop(&S, line) == 1 ){
		printf("%s",line);
	}
	
	return 0;
}

