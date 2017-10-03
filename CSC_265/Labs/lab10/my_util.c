#include "my_util.h"

void init_array(int* my_array, unsigned int max_elements) {
	for(int i=0; i<max_elements; i++) {
		my_array[i] =  rand() % max_elements;
	} 
}

void print_array(int* my_array, unsigned int max_elements) {
	for(int i=0; i<max_elements; i++) { 
		printf("%d  ", my_array[i]);
	}
}
