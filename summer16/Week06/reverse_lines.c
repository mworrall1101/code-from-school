/* reverse_lines.c

   A program to read in every line of standard input, then
   print the lines out in reverse order.


  
   B. Bird - 06/10/2016
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX_LINE 99



#define STACK_STRING_SIZE 100

typedef struct StringStackNode{
	char str[STACK_STRING_SIZE];
	struct StringStackNode* next;
} StringStackNode;

typedef struct{
	
	StringStackNode* head;
	
} StringStack;


/* StringStack_Push(S,str)
   Push the provided string str onto the stack S.
   
   Pre-conditions:
     S is a pointer to a StringStack struct.
     str is a pointer to a null terminated C string
     of length at most STACK_STRING_SIZE.
   Post-conditions:
     A new node containing a copy of str has been
     added as the first node of S.
*/ 
void StringStack_Push(StringStack* S, char* str){
	StringStackNode* new_node = (StringStackNode*)malloc(sizeof(StringStackNode) );
	new_node->next = S->head;
	S->head = new_node;
	strcpy( new_node->str, str);
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
	if (S->head == NULL)
		return 0;
	StringStackNode* delete_node = S->head;
	S->head = delete_node->next;
	//S->head = S->head->next;
	//(*S).head = (*(*S).head).next;
	delete_node->next = NULL;
	strcpy( buffer, delete_node->str );
	free( delete_node );
	return 1;
}
	



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

