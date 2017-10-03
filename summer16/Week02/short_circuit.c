/* short_circuit.c


   B. Bird - 05/11/2016
*/

#include <stdio.h>

int return_one(){
	printf("Returning 1\n");
	return 1;
}

int return_two(){
	printf("Returning 2\n");
	return 2;
}
int main(){
	
	if( return_one() == 2 && return_two() == 2){
		printf("Condition was true\n");
	}else{
		printf("Condition was false\n");
	}

	return 0;
}
