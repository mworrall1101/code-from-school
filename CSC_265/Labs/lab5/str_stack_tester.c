/* string_list_tester.c
  
    University of Victoria, Dept. of Computer Science
    SENG 265 - Summer 2016
    Lab
   
    Template for a tester for the StrStack datatype.
     
    Originally written by B. Bird to test StringList datatype
    Edited by Tom Arjannikov for lab purposes to test StrStack datatype
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_stack.h"

#define TEST_FAILED 0
#define TEST_PASSED 1
#define ASSERT(condition, msg) if (!(condition)) {printf("\nError: %s\n", msg); return TEST_FAILED;}
/* Each of the test functions below should return TEST_FAILED if the test fails
   and TEST_PASSED if the test is passed.
*/

int test1(){
	//First test: StrStack_init() 

    StrStack* my_stack = NULL;
    StrStack_Init(&my_stack);

    if(my_stack == NULL) return TEST_FAILED;
    if(my_stack->head != NULL) return TEST_FAILED;
    if(my_stack->size != 0) return TEST_FAILED;

    if(StrStack_Size(my_stack) != 0) return TEST_FAILED;

    StrStack_Destroy(&my_stack);
	return TEST_PASSED;
}

int test2(){
	//Second test

    StrStack* my_stack = NULL;
    StrStack_Init(&my_stack);
    return TEST_FAILED;

    StrStack_Destroy(&my_stack);
	return TEST_PASSED;
}

int test3(){
    //Third test
    	StrStack* my_stack = NULL;
	StrStack_Init(&my_stack);
	StrStack_Push(my_stack, "word");
	//if(StrStack_Size(my_stack) != 1)return TEST_FAILED;
	ASSERT(StrStack_Size(my_stack) == 1, "Size is not 1 after pushing a string");
	StrStack_Destroy(&my_stack);
	//if(!StrStack_Empty(my_stack))	return TEST_FAILED;
	ASSERT(StrStack_Empty(my_stack), "List not empty after Destroy");
    return TEST_FAILED;
}

int test4(){
    //Fourth test
	
    return TEST_FAILED;
}

int test5(){
	//Fifth test

    return TEST_FAILED;
}

int test6(){
	//Sixth test

    return TEST_FAILED;
}

int test7(){
	//Seventh test

    return TEST_FAILED;
}

int test8(){
	//Eighth test 

    return TEST_FAILED;
}




/* Do not change any of the code below, to ensure consistency during all vs. all testing */

void show_usage(){
	fprintf(stderr,"Usage: ./string_list_tester <test_number>\n");
	fprintf(stderr,"Where <test_number> is an integer between 1 and 8.\n");
}

int main(int argc, char** argv){
	if (argc < 2){
		show_usage();
		return 0;
	}
	//The atoi function converts a string to an integer (and returns 0 if
	//the conversion fails).
	int test_number = atoi(argv[1]);
	
	if (test_number <= 0 || test_number > 8){
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
		case 3:
			result = test3();
			break;
		case 4:
			result = test4();
			break;
		case 5:
			result = test5();
			break;
		case 6:
			result = test6();
			break;
		case 7:
			result = test7();
			break;
		case 8:
			result = test8();
			break;
	}
	
	if (result != TEST_PASSED)
		printf("\nTEST %d FAILED\n", test_number);
	
	return 0;
}
