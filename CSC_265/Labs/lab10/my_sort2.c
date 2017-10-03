#include "my_sort.h"
#include "my_util.h"

int my_min(int* my_array, int max_elements) {


	unsigned int curr_idx=0;
	int curr_min = my_array[curr_idx];

	for(int i=1; i<max_elements; i++) {
		if(my_array[i] < curr_min) {
			curr_idx = i;
			curr_min = my_array[curr_idx];
		}
	}

	return curr_idx;
}

void my_sort(int* my_array, int max_elements) {
	for(int i=0; i<max_elements-1; i++) {
		int min_idx = my_min(my_array+i, max_elements-i) + i;
		int temp = my_array[i];
		my_array[i] = my_array[min_idx];
		my_array[min_idx] = temp;
	}
}
