/* list.c
  
   B. Bird - 06/08/2016
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
struct StudentStruct {
	float grade;
	char name[100];
	struct StudentStruct* next;
};

typedef struct StudentStruct Student;
*/

typedef struct IntListNode{
	int element;
	struct IntListNode* next;
} IntListNode;

typedef struct{
	IntListNode* head;
} IntList;

void IntList_Print( IntList* list ){
	IntListNode* current = (*list).head; // Could also use list->head
	while ( current != NULL ){
		printf("%d ", current->element );
		current = current->next;
	}
	printf("\n");
}

void IntList_Add( IntList* list, int element ){
	
	IntListNode* new_node = (IntListNode*)malloc( sizeof(IntListNode)  );
	if (list->head == NULL){
		//The list is currently empty.
		new_node->next = NULL;
		list->head = new_node;
		new_node->element = element;
	}else{
		//Adding to a list with at least one element.
		new_node->next = list->head;
		list->head = new_node;
		new_node->element = element;
	}

}

int main(){
	
	IntList L;
	L.head = NULL; 

	IntList_Add( &L, 10 );
	IntList_Add( &L, 6 );
	IntList_Print( &L );
	IntList_Add( &L, 17 );
	IntList_Print( &L );


	return 0;
}

