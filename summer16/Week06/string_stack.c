/* string_stack.c
  
   
   B. Bird - 06/10/2016
*/

#include <stdlib.h>
#include <string.h>
#include "string_stack.h"

void StringStack_Push(StringStack* S, char* str){
	StringStackNode* new_node = (StringStackNode*)malloc(sizeof(StringStackNode));
	strcpy(new_node->str,str);
	new_node->next = S->head;
	S->head = new_node;
}


/* StringStack_Pop(S, buffer)
   If the stack is empty, returns 0 immediately.
   Otherwise, this function copies the contents
   of the first element of S into the provided 
   buffer (which must have size at least 
   STACK_STRING_SIZE), then removes the first node
   from the list (and deletes all associated storage)
   and returns 1.

   Pre-conditions:
     S is a pointer to a StringStack struct.
     buffer is a pointer to an array of length
     at least STACK_STRING_SIZE.
   Post-conditions:
     The first node of S has been deleted.
*/ 
int StringStack_Pop(StringStack* S, char* buffer){
	StringStackNode* top = S->head;
	if (top == NULL)
		return 0;
	//Splice top out of S
	S->head = top->next;
	
	strcpy(buffer,top->str);
	free(top);
	return 1;
}
