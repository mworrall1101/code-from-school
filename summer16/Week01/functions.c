/* functions.c


   B. Bird - 05/06/2016
*/

#include <stdio.h>

int square(int x){
	int not_the_result = x*x*x;
	int result = x*x;
	return result; //Try commenting this out.
}


int main(){
	int A = 10;
	int A_squared = square(A);
	printf("%d squared is %d\n",A, A_squared);
	return 0;
}
