#include "my_util.h"
#include "my_sort.h"

int main(int argc, char* argv[]) {

	srand(0);

	int max_elements = 10;

	if(argc > 1)  
		max_elements = atoi(argv[1]);

	int test_array[max_elements];

	init_array(test_array, max_elements);

//	print_array(test_array, max_elements);
//	printf("\n\n");

	my_sort(test_array, max_elements);
	
//	print_array(test_array, max_elements);
//	printf("\n\n");

}
