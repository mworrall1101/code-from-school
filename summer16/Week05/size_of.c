/* size_of.c

   B. Bird - 05/31/2016
*/

#include <stdio.h>
#include <string.h>

#define Z_SIZE (11)

void F(int* A){
	printf("In F: size of A: %d\n",sizeof(A));
	printf("In F: size of A[0]: %d\n", sizeof(A[0]) );
}


int main(){
	int Z[Z_SIZE];
	int x;
	double g;
	int* p;
	double* q;
	printf("size of x: %d\n", sizeof(x));
	printf("size of g: %d\n", sizeof(g));
	printf("size of p: %d\n", sizeof(p));
	printf("size of q: %d\n", sizeof(q));
	printf("size of Z: %d\n", sizeof(Z));
	printf("size of Z: %d\n", sizeof(Z)/sizeof(Z[0]) );
	F(Z);
	return 0;
}
