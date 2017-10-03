/* string_stack_tester.c

   To compile:
     gcc -Wall -std=c99 -o string_stack_tester string_stack.c string_stack_tester.c

   B. Bird - 06/14/2016
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_stack.h"


#define TEST_FAILED 0
#define TEST_PASSED 1

/* Each of the test functions below should return TEST_FAILED if the test fails
   and TEST_PASSED if the test is passed.
*/

int test1(){
	/* This function uses a "black box" testing protocol, where
	   only the public interface of the data structure is used,
	   instead of looking at the internals.
	*/
	StringStack S;
	
	char* test_strings[] = {"String 1", "String 2", "String 3", "String 4"};

	printf("Pushing the four test strings onto the stack.\n");
	int i;
	for (i = 0; i < 4; i++){
		StringStack_Push(&S, test_strings[i]);
	}

	printf("Running four pop operations.\n");
	printf("Output: ");
	for(i = 3; i >= 0; i--){
		char buffer[STACK_STRING_SIZE];
		int success = StringStack_Pop(&S,buffer);
		if (!success){
			printf("\nError: Pop %d reported an empty stack\n",i);
			return TEST_FAILED;
		}
		//The strcmp function returns 0 if the two strings
		//given as arguments are equal (case sensitive).
		if (strcmp(test_strings[i],buffer) == 0){
			printf("%s, ", buffer);
		}else{
			printf("\nError: Pop %d produced an invalid string.\n",i);
		}
	}
	printf("\n");
	//Idea: check that a pop operation at this point
	//returns 0, since the stack should be empty.
		
	return TEST_PASSED;
}

int test2(){

	/* This function uses a "glass box" testing protocol, where
	   the tester is allowed access to the complete internal
	   state of the data structure.
	*/
	StringStack S;
	char* test_strings[] = {"String 1", "String 2", "String 3", "String 4"};

	printf("Pushing the four test strings onto the stack.\n");
	int i;
	for (i = 0; i < 4; i++){
		StringStack_Push(&S, test_strings[i]);
		//Check that the head of the list now contains
		//the inserted string
		if (S.head == NULL){
			printf("Error: head is NULL after push %d\n",i);
			return TEST_FAILED; 
		}
		if(strcmp(S.head->str,test_strings[i]) != 0){
			printf("Error: head contains incorrect value (%s) after push %d\n",S.head->str,i);
			return TEST_FAILED; 
		}
	}

	printf("Running four pop operations.\n");
	printf("Output: ");
	for(i = 3; i >= 0; i--){
		char buffer[STACK_STRING_SIZE];
		int success = StringStack_Pop(&S,buffer);
		if (!success){
			printf("\nError: Pop %d reported an empty stack\n",i);
			return TEST_FAILED;
		}
		if (strcmp(test_strings[i],buffer) == 0){
			printf("%s, ", buffer);
		}else{
			printf("\nError: Pop %d produced an invalid string.\n",i);
		}
		if (i > 0){
			//If i is greater than 0, the stack should still be non-empty.
			if (S.head == NULL){
				printf("\nError: Stack is empty before last pop operation\n");
				return TEST_FAILED;
			}
			if (strcmp(S.head->str,test_strings[i-1]) != 0){
				printf("\nError: After pop %d, the top of the stack contains an invalid value (%s)\n",i,S.head->str);
				return TEST_FAILED;
			}
		}else{
			//If i is 0, the stack should be empty and head should be NULL
			if (S.head != NULL){
				printf("\nError: Stack is non-empty after last pop\n");
				return TEST_FAILED;	
			}
		}
	}
	printf("\n");
	return TEST_PASSED;
}



void show_usage(){
	fprintf(stderr,"Usage: ./string_stack_tester <test_number>\n");
	fprintf(stderr,"Where <test_number> is an integer between 1 and 2.\n");
}

int main(int argc, char** argv){
	if (argc < 2){
		show_usage();
		return 0;
	}
	//The atoi function converts a string to an integer (and returns 0 if
	//the conversion fails).
	int test_number = atoi(argv[1]);
	
	if (test_number <= 0 || test_number >= 3){
		show_usage();
		return 0;
	}
	
	int result = 1;
	switch(test_number){
		case 1:
			result = test1();
			break;
		case 2:
			result = test2();
			break;
	}
	
	if (result == TEST_PASSED){
		printf("\nTEST PASSED\n");
	}else{
		printf("\nTEST FAILED\n");
	}
	return 0;
}
