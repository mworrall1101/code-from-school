/* string_list.h
  
    University of Victoria, Dept. of Computer Science
    SENG 265 - Summer 2016
    Lab 
  
    Declarations for a dynamically allocated stack of c-strings.
  
    Written by Tom Arjannikov
*/


// One node in the data structure
typedef struct StrStackNode{
	char* data;
	struct StrStackNode* next;
} StrStackNode;

// User interface to the data structure
typedef struct{
	StrStackNode* head;
    unsigned int size;
} StrStack;

/* StrStack_Init(&S)
   Initialize StrStack instance.
   
   Pre-conditions:
     S is a StrStack type NULL-pointer.
   Post-conditions:
     StrStack struct is allocated on heap
     S points to this StrStack heap memory
     S->head is NULL 
     S->size is 0
*/ 
void StrStack_Init(StrStack**);

/* StrStack_Destroy(&S)
   Free all memory associated with S

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
    S->head may point to previously allocated heap memory
   Post-conditions:
    memory associated with each string inside each node is freed
    memory assiciated with each node is freed
    memory assiciated with StrStack is freed
    S is NULL
*/
void StrStack_Destroy(StrStack**);

/* StrStack_Empty(S)
   Tests if S is empty

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
   Return Value:
    1 if S is empty
    0 if S is not empty
*/
int StrStack_Empty(StrStack*);

/* StrStack_Size(S)
   Return the number of nodes in the stack S

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
   Return Value:
    number of elements in the data structure
*/
int StrStack_Size(StrStack*);

/* StrStack_Push(S, str)
   Puts str on top of the stack S

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
    str points to a valid c-string
   Post-conditions:
    memory is allocated to store the new node
    memory is allocated to store a copy of str
    new node is inserted at the top of the stack data structure
   Return Value:
    1 if everything went well
    0 otherwise
*/
int StrStack_Push(StrStack*, char*);

/* StrStack_Pop(S)
   Removes and returns the top element on the stack S

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
   Post-conditions:
    top node on the stack S is removed, memory assiciated with it is freed
   Return Value:
    pointer to newly allocated memory containing a valid c-string
*/
char* StrStack_Pop(StrStack*);

/* StrStack_Top(S)
   Returns a copy of the top element on he stack S

   Pre-conditions:
    S points to StrStack that was previously initialized via StrStack_Init()
   Return Value:
    pointer to newly allocated memory containing a valid c-string
*/
char* StrStack_Top(StrStack*);

/* copy_str(str)  <-- Utility function
   Returns a pointer to a copy of str in newly allocated heap memory

   Pre-conditions:
    str is a valid c-string (may be empty)
   Post-conditions:
    New memory is allocated on the heap
    Contents of str are copied to the newly allocated memory
   Return Value:
    Pointer to a valid c-string in heap memory
*/
char* copy_str(char*);

