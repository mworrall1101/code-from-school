#include "my_sort.h"
#include "my_util.h"

void my_sort(int* my_array, int max_elements) {
	int sorted = 0;
	while(!sorted) {
		sorted = 1;
		for(int i=0; i<max_elements-1; i++) {
			if(my_array[i] > my_array[i+1]) {
				int tmp = my_array[i];
				my_array[i] = my_array[i+1];
				my_array[i+1] = tmp;
				sorted = 0;
			}
		}
	}
}
