/* reverse_lines.c

   A program to read in every line of standard input, then
   print the lines out in reverse order.


  
   B. Bird - 06/10/2016
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

