/* broken_string_stack.c
  
   
   B. Bird - 06/14/2016
*/

#include <stdlib.h>
#include <string.h>
#include "string_stack.h"


void StringStack_Push(StringStack* S, char* str){
	StringStackNode* new_node = (StringStackNode*)malloc(sizeof(StringStackNode));
	strcpy(new_node->str,str);
	new_node->next = S->head;
	S->head = new_node;

	/* Broken: Lose the pointer to the rest of the list */
	new_node->next = NULL;
}


int StringStack_Pop(StringStack* S, char* buffer){
	StringStackNode* top = S->head;
	/* Broken: Don't check if the stack is empty
	if (top == NULL)
		return 0;
	*/
	//Splice top out of S
	S->head = top->next;
	
	strcpy(buffer,top->str);
	free(top);
	return 1;
}
