/* arrays.c


   B. Bird - 05/06/2016
*/

#include <stdio.h>

int square(int x){
	int result = x*x;
	return result;
}


int main(){
	int i;
	int A[10];

	for(i = 0; i < 10; i++)
		A[i] = square(i);

	for(i = 0; i < 10; i++){
		printf("A[%d] = %d\n",i,A[i]);
	}

	return 0;
}






