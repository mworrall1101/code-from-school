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
#include <malloc.h>

#define TEST_FAILED 0
#define TEST_PASSED 1

/* Each of the test functions below should return TEST_FAILED if the test fails
   and TEST_PASSED if the test is passed.
*/

int test1(){

    StrStack* my_stack = NULL;
    char* test;

    malloc_stats();

    StrStack_Init(&my_stack);

    if(my_stack == NULL) return TEST_FAILED;
    if(my_stack->head != NULL) return TEST_FAILED;
    if(my_stack->size != 0) return TEST_FAILED;

    if(StrStack_Size(my_stack) != 0) return TEST_FAILED;

    StrStack_Push(my_stack, "abc");
    if(StrStack_Size(my_stack) != 1) return TEST_FAILED;

    test = StrStack_Top(my_stack);
    printf("\n%s\n",test);
    if(strcmp("abc", test)) return TEST_FAILED;
    free(test);

    test = StrStack_Pop(my_stack);
    if(strcmp("abc", test)) return TEST_FAILED;
    if(StrStack_Size(my_stack) != 0) return TEST_FAILED;
    free(test);
    
    StrStack_Push(my_stack, "abc");
    StrStack_Push(my_stack, "abc");
    StrStack_Push(my_stack, "abc");
    StrStack_Push(my_stack, "abc");

    StrStack_Destroy(&my_stack);

    malloc_stats();

    return TEST_PASSED;
}

int test2(){
    return TEST_FAILED;
}

int test3(){
    return TEST_FAILED;
}

int test4(){
    return TEST_FAILED;
}

int test5(){
    return TEST_FAILED;
}

int test6(){
    return TEST_FAILED;
}

int test7(){
    return TEST_FAILED;
}

int test8(){
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
