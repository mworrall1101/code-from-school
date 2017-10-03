/* string_stack.h
  
   
   B. Bird - 06/10/2016
*/

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
void StringStack_Push(StringStack* S, char* str);


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
int StringStack_Pop(StringStack* S, char* buffer);
