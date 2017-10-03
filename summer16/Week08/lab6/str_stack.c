/* str_stack.c
  
    University of Victoria, Dept. of Computer Science
    SENG 265 - Summer 2016
    Lab
  
    Implementation of str_stack.h
     
    Written by Tom Arjannikov
*/

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "str_stack.h"

void StrStack_Init(StrStack** S) {
    assert(S != NULL);
    assert(*S == NULL);
    (*S) = malloc(sizeof(StrStack));
    (*S)->head = NULL;
    (*S)->size = 0;
}

void StrStack_Destroy(StrStack** S) {
    assert(S != NULL);
    assert((*S) != NULL);
    if((*S)->head != NULL) { 
        StrStackNode* iterator = (*S)->head;
        while(iterator->next != NULL) {
            StrStackNode* tmp = iterator->next;
            free(iterator->data);
            free(iterator);
            iterator = tmp;
        }
        free(iterator->data);
        free(iterator);
        (*S)->head = NULL;
        (*S)->size = 0;
    }
    free(*S);
    (*S) = NULL;
}

int StrStack_Empty(StrStack* S) {
    assert(S != NULL);
    if(S->size == 0)
        return 0;
    else
        return 1;
}

int StrStack_Size(StrStack* S) {
    assert(S != NULL);
    return S->size;
}

int StrStack_Push(StrStack* S, char* str) {
    assert(S != NULL);
    unsigned int len = strlen(str);

    StrStackNode* new_node = malloc(sizeof(StrStackNode));
    if(new_node == NULL) 
        return 0;

    new_node->data = malloc(sizeof(char*)*(len+1));
    if(new_node->data == NULL) {
        free(new_node);
        return 0;
    }

    new_node->next = S->head;
    S->head = new_node;
    S->size += 1;

    memcpy(new_node->data, str, len+1);
    return 1;
}

char* StrStack_Pop(StrStack* S) {
    assert(S != NULL);
    char* ret_str = S->head->data;
    if(S->head != NULL) {
        StrStackNode* tmp = S->head;
        S->head = S->head->next;
        free(tmp);
        S->size -= 1;
    }
    return ret_str;
}

char* StrStack_Top(StrStack* S) {
    assert(S != NULL);
    char* new_str = NULL;
    if(S->head != NULL) {
        new_str = copy_str(S->head->data);
    }
    return new_str; 
}

char* copy_str(char* str) {
    assert(str != NULL);
    unsigned int len = strlen(str);
    char* new_str = NULL;
    assert(new_str = malloc(len+1));
    memcpy(new_str, str, len+1);
    return new_str;
}
